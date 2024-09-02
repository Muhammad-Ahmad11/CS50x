#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Header.h"
using namespace std;

int main() {
	ifstream in;
	string a;
	string b;
	int x = 0;

	in.open("Users.txt", ios::in);
	char c;
	in >> x;
	Page* page = new Page[12];
	ifstream fin;
	fin.open("Pages.txt", ios::in);
	fin >> x;
	for (int i = 0; i < 12; i++) {
		fin >> c;
		fin >> x;
		//in.ignore();
		page[i].setid(x);
		getline(fin, a);
		page[i].setname(a);


	}
	user* u = new user[20];
	for (int i = 0; i < 20; i++) {
		in >> c;
		in >> x;
		//in.ignore();
		u[i].setid(x);
		in >> a;
		in >> b;
		u[i].setnames(a, b);

		for (int j = 0; x != -1; j++) {
			in >> c;
			if (c == '-') {
				in >> x;
				x = -1;
				continue;
			}
			in >> x;

			u[i].userids[j] = x;

		}
		x = 0;
		for (int j = 0; x != -1; j++) {
			in >> c;
			if (c == '-') {
				in >> x;
				x = -1;
				continue;
			}
			in >> x;

			u[i].pagesids[j] = x;
		}

	}

	for (int i = 0; i < 20; i++) {


		for (int k = 0; u[i].pagesids[k] > 0; k++) {
			u[i].setpages(page[u[i].pagesids[k] - 1]);
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int k = 0; u[i].userids[k] > 0; k++) {
			u[i].setfriends(u[u[i].userids[k] - 1]);

		}
	}

	string comand;
	string g = "view friends list";

	int sizepost = 0;
	string name = "English";

	ifstream rep;
	char r;
	string s;
	int t1, t2;
	rep.open("Posts.txt", ios::in);
	activity* posts = new activity[11];
	rep >> sizepost;
	int v = 0;
	int l = 0;
	int c12 = 0;
	Date* d = new Date[11];
	for (int i = 0; i < sizepost; i++) {

		rep >> s;
		rep >> t1;
		posts[i].obj::setid(t1);

		rep >> t2;
		d[i].setday(t2);
		rep >> t2;
		d[i].setmonth(t2);
		rep >> t2;
		d[i].setyear(t2);
		posts[i].setdate(d[i]);
		getline(rep, s);
		getline(rep, s);

		posts[i].setdes(s);
		rep >> t1;

		if (t1 != 0) {
			posts[i].settype(t1);
			getline(rep, s);
			posts[i].setvalue(s);
		}
		rep >> r;

		if (r == 'u') {
			rep >> t1;
			posts[i].setsharedpost(u[t1 - 1]);
			u[t1 - 1].postsids[u[t1 - 1].countposts] = i + 1;

			u[t1 - 1].countposts++;


		}
		else if (r == 'p') {
			rep >> t1;
			posts[i].setsharedpost(page[t1 - 1]);
			page[t1 - 1].postsids[page[t1 - 1].count] = i + 1;

			page[t1 - 1].count++;
		}
		t1 = 0;
		for (int j = 0; t1 != -1; j++) {
			rep >> r;
			if (r == '-') {
				rep >> t1;
				t1 = -1;
				continue;
			}
			else if (r == 'u') {
				rep >> t1;

				posts[i].setlikedpost(u[t1 - 1]);

			}
			else if (r == 'p') {
				rep >> t1;
				posts[i].setlikedpost(page[t1 - 1]);
			}
		}
		cout << endl;
	}


	for (int i = 0; i < 20; i++) {
		for (int k = 0; k < 10; k++) {
			if (u[i].postsids[k] != 0) {
				u[i].setposts(posts[u[i].postsids[k] - 1]);

			}
		}
	}

	cout << endl;
	for (int i = 0; i < 12; i++) {
		for (int k = 0; k < 10; k++) {
			if (page[i].postsids[k] != 0) {
				page[i].setposts(posts[page[i].postsids[k] - 1]);
			}
		}
	}
	int k1 = 0;
	int m = 10;
	int y = 2017;
	int day = 14;


	int size;
	ifstream f;
	f.open("Comments.txt");
	f >> size;
	comment* arr_com = new comment[20];

	int noofcomms = 0;

	int y23 = 0;
	for (int i = 0; i < size; i++)
	{
		f >> c;
		f >> y23;
		arr_com[i].obj::setid(y23);

		for (int j = 0; j < 4; j++)
			f >> c;
		f >> x;

		if (i == 4) {

		}
		posts[x - 1].commids[posts[x - 1].count] = y23;
		posts[x - 1].count++;
		f >> c;
		if (c == 'u') {
			f >> x;
			arr_com[i].setusers(u[x - 1]);
		}
		else if (c == 'p') {
			f >> x;
			arr_com[i].setpagename(page[x - 1]);
		}
		getline(f, s);
		arr_com[i].setdes(s);
		noofcomms++;
	}
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			if (posts[i].commids[j] != 0) {

				posts[i].setusercommentid(arr_com[posts[i].commids[j] - 1]);
			}
		}
	}



	activity::run(posts, u, page, arr_com, noofcomms);


	delete[]page;
	page = nullptr;
	delete[]u;
	u = nullptr;
	delete[]posts;
	posts = nullptr;
	delete[]arr_com;
	arr_com = nullptr;




}
