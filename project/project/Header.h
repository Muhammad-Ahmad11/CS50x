#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class activity;
class post;
class Date;
class user;
class comment;

class obj {
	int id;
public:
	obj();
	int getid();
	void setid(int x);
};
class Page :public obj {

	string name;
	user** likedpeople;
	activity** posts;

public:
	int count;
	int* postsids;
	Page();
	void setid(int x);
	Page(string names);
	void setname(string a);
	string getname();
	void setusers(user& obj);
	void setposts(activity& obj);
	void print();
	activity* getposts(int a);
	~Page();

};

class user :public obj {

	string firstname;
	string lastname;
	int activityx;
	user** friends;
	activity** posts;
	Page** pages;
	int countfriends;
	int countpages;
public:
	int countposts;


	int* postsids;
	int* pagesids;
	int* userids;
	int* commids;
	void HOmepage(int d, int m, int y);
	user();
	user(string ids, string lname, string fname);
	void setnames(string a, string b);
	string getnames();
	string getfname();
	string getlname();
	void setid(int x);
	void printfriends();
	void printposts();
	void printlikedpages();
	void setposts(activity& obj);
	void setfriends(user& obj);
	void setpages(Page& obj);
	void Timeline();

	~user();
};
class Date :public obj {
	int month;
	int day;
	int year;
public:
	Date();
	Date(int d, int m, int y);
	void setday(int d);
	int getday();
	void setmonth(int m);
	int getmonth();
	void setyear(int y);
	int getyear();
	void print();
};
class comment :public obj {
	user* users;
	activity** pagename;
	Page* page;
	string des;
	int count;

public:
	comment();
	comment(string des, user** users);
	void setid(int id);
	void setdes(string des);
	string getdes();
	void setusers(user& obj);
	void setpagename(Page& obj);
	void print();
	~comment();
};
class Post :public obj {
	string description;
	user** likedpostsbyuser;
	Page** likedpostbypage;
	user* sharedpostbyuser;
	Page* sharedpostbypage;
	comment** commid;
	int countcomments;
	Date* shareddate;

	int countlikedpeople;
	int countlikedpages;
public:
	int count;
	int* commids;

	Post();
	Post(string des, user** likedposts);
	void setusercommentid(comment& obj);
	void setlikedpost(Page& obj);
	void setlikedpost(user& obj);
	void setdate(Date& d);
	void setsharedpost(user& obj);
	void setsharedpost(Page& obj);
	user* getsharedpostbyuser();
	Date* getsharedpostDate();
	Page* getsharedpostbypage();
	void setdes(string des);
	void setid(int x);
	string getdescription();
	void printdate();
	void print();
	void print2();
	void likes();

	~Post();
};
class activity :public Post {
	int type;
	string value;
	string description;
public:
	activity();
	void setvalue(string des);
	void settype(int x);
	int gettype();
	string getvalue();
	static void search(string name, activity* post, user* u, Page* page, comment* arr_comm);
	static void run(activity* post, user* u, Page* page, comment* arr_comm, int n);

	void print();
};

