#pragma once

#include <random>
#include <iostream>
#include "Time.h"
using namespace std;

template <class T>
class Vector
{
public:

	Vector();
	Vector(int s, T k);
	Vector(const Vector<T>& a);
	~Vector();

	Vector& operator=(const Vector<T>& a);
	T& operator[](int index);
	Vector operator+(const T k);
	Vector& operator*(const Vector<T>& a);
	int operator()();

	void push_back(T);

	void insert(int, T);

	void make(int n);

	void print();

	void add_mean(int k);

	void del();

	void decrease_mean();

	int operator()() const;

	friend ostream& operator<< (ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);
private:
	int size;
	T* data;
};


template<class T>
int Vector<T>::operator()() const {
	return size;
}

template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}

template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

template <class T>
Vector<T> Vector<T>::operator+(const T k)
{
	Vector<T> temp(size, k);
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}

template <class T>
Vector<T>& Vector<T>::operator*(const Vector<T>& a)
{
	Vector<T> temp;
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] * a.data[i];
	return temp;
}

template <class T>
int Vector<T>::operator ()()
{
	return size;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	for (int i = 0; i < size; ++i)
		data[i] = data[i] * a.data[i];
	return *this;
}

template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}

template<class T>
void Vector<T>::push_back(T k) {
	T* tmp = data;
	data = new T[size + 1];
	for (int i = 0; i < size; ++i) {
		data[i] = tmp[i];
	}
	delete[] tmp;
	data[size] = k;
	++size;
}

template<class T>
void Vector<T>::insert(int pos, T k) {
	T* tmp = data;
	int ps = size;
	data = new T[size + 1];
	for (int i = 0; i < size; ++i) {
		if (i == pos) {
			data[i] = k;
			++size;
		}
		data[i + size - ps] = tmp[i];
	}
	if (size == ps) {
		data[size] = k;
		size++;
	}
	delete[] tmp;
}

template<class T>
void Vector<T>::make(int n) {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<double> distr(-100, 100);
	for (int i = 0; i < n; ++i) {
		Time p;
		p.set_min(distr(eng));
		p.set_sec(distr(eng));
		push_back(p);
	}
}

template<class T>
void Vector<T>::print() {
	for (int i = 0; i < size; ++i) {
		cout << data[i] << ' ';
	}
	cout << endl;
}

template<class T>
void Vector<T>::add_mean(int k) {
	int min = 0;
	int sec = 0;
	int minim = 1000;
	for (int i = 0; i < size; ++i) {
		if ((data[i].get_min() * 60 + data[i].get_sec()) < minim)
		{
			minim = data[i].get_min() * 60 + data[i].get_sec();
		}
	}
	min = minim / 60;
	sec = minim % 60;
	insert(k, Time(min, sec));
}

template<class T>
void Vector<T>::del() {
	Vector<T> tmp;
	int min = 0;
	int sec = 0;
	for (int i = 0; i < size; ++i) {
		min += data[i].get_min();
		sec += data[i].get_sec();
	}
	min /= size;
	sec /= size;
	Time sredn(min, sec);
	for (int i = 0; i < size; ++i) {
		if (data[i] > sredn) {
			tmp.push_back(data[i]);
		}
	}
	size = tmp.size;
	T* to_del = data;
	data = tmp.data;
	delete[] to_del;
	tmp.data = nullptr;
}

template<class T>
void Vector<T>::decrease_mean() {
	int min = 0;
	int sec = 0;
	int max = 1000;
	for (int i = 0; i < size; ++i) {
		if ((data[i].get_min() * 60 + data[i].get_sec()) > max)
		{
			max = data[i].get_min() * 60 + data[i].get_sec();
		}
	}
	min = max / 60;
	sec = max % 60;
	Vector<T> tmp;
	for (int i = 0; i < size; ++i) {
		tmp.push_back(Time(data[i].get_min() * min, data[i].get_sec() * sec));
	}
	T* to_del = data;
	data = tmp.data;
	delete[] to_del;
	tmp.data = nullptr;
}

template<class T>
Vector<T>::Vector() {
	size = 0;
	data = new T[0];
}