#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)return -1;
	int n;
	Time p;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p;
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Time p; int i = 0;
	while (stream>>p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Time k1 , Time k2)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	int i = 0; Time p;
	while (stream >> p)
	{
		
		if (stream.eof())break;
		i++;
		
		if (k1 > p || p > k2)
			temp << p;
	}
	
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Time p, o;
	int n = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> o;
		temp << o;
	}
	while (stream >> p)
	{
		if (stream.eof())break;
		n++;
		temp << p;

	}

	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return n;

}

int plus_file(const char* f_name, Time k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Time p;
	Time m(1, 30);
	int i = 0;
	while (stream >> p)
	{
		if (p == k)
		{
			p = p + m;
		}
		i++;
		temp << p;
	}

	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}