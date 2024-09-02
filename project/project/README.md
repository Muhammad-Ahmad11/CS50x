#Console based social media application
## https://youtu.be/ZtPxD6QGPo8
#CS50
>This was my final project to conclude the CS50 Introduction to Computer Sciense course.

##Description:
    This project is based on **C++** language **OOP(Object Oriented Programming)** concepts.I have made this project on visual studio 2019.Please run this project on
    Visual studio 2019 for better experience.Concepts like:
-Pointers
-Dynamic memory allocation
-Association
-Aggregation
-Composition
-Polymorphism(Compile Time polymorphism)
-File handling
are used in making this project.

##Structure:
        I have divided the whole project into 3 files which are:
        -Main.cpp
        -Header.cpp
        -Function.cpp

Main.cpp contains the **int main()** function and in order to make it less messy i have placed the function headers in **Headers.h** file and the definations of
those functions in **Function.cpp** file.

##Working:
    This apps basically read data from txt file.I have removed comments from Posts.txt, Pages.txt, Users.txt and Comments.txt files because i have to read data
from them but you can see SocialNetworkUsers, SocialNetworkPages, SocialNetworkPosts, SocialNetworkPosts and SocialNetworkComments files for viewing the same data
but with comment for better understanding.So that, you may know that how data is actually stored in the txt files.

We have declared dynamic arrays of pages, activity, comments and users to read data form files and later on stored them in their classes accordingly.
And then read use that data for accessing the information of any particular user based on txt files.The execution of this project is below.

##Execution:
       When we execute this **Main.cpp** .We will we following text on the console:
As when we store data in arrays we first store at index zero then onwards.So, in accessing data form arrays 0 id is displayed because of that condition for user
having id 1 and similar is in case of posts, pages and comments.



###Output:

**********************************************************************Welcome*************************************************************************************

Please select the current user for this application first to continue:
0.Amna Akram
1.Muhammad Ali
2.Waheed Khan
3.Burhan Tahir
4.Hassan Sohail
5.Saad Ali
6.Abdullah Nadeem
7.Nimra Batool
8.Abubakar Javed
9.Saad Sultan
10.Ahsan Ali
11.Kamal Subhani
12.Saad Ahmed
13.Usman Usman
14.Zaid Tariq
15.Abdullah Siddiqui
16.Saif ullah
17.Hashir Baig
18.Usama Jawad
19.Haris Muneer

Enter id no.:

Here we need to enter id of user which we want to sert as our current user:

lets enter 6 for this

Comand :    set users
Abdullah Nadeem succesfully set as current user
Comand :   set current date

Then ,following menu will be displayed:

Enter 1 for  viewing friends of current user
Enter 2 for viewing liked pages
Enter 3 for view the likes of any post you want
Enter 4 if you want to like any post
Enter 5 for viewing timeline liked
Enter 6 for viewing any page
Enter 7 for viewing homepage
Enter 8 to comment on any post
Enter 9 to view any post
Enter 10 to share any post
Enter 11 to search any word in any post you want to find that post
Enter -1 to exit

if we hit 1 we got:

Command    view Friends
Enter user id whose friends you want to view:

As id of our user is 6 so entering 6:

We can check this even from txt files the information is always same:

Friends List :

u3--  Waheed  Khan
u11--  Ahsan  Ali
u12--  Kamal  Subhani

--------------------------------------------------------------

Then ,following menu will be displayed:

Enter 1 for  viewing friends of current user
Enter 2 for viewing liked pages
Enter 3 for view the likes of any post you want
Enter 4 if you want to like any post
Enter 5 for viewing timeline liked
Enter 6 for viewing any page
Enter 7 for viewing homepage
Enter 8 to comment on any post
Enter 9 to view any post
Enter 10 to share any post
Enter 11 to search any word in any post you want to find that post
Enter -1 to exit

Hitting 3;

command   view Post likes
Enter post id whose likes you want to view from 0 to 10: entering 1
Post liked by :
        Abdullah Nadeem

--------------------------------------------------------------

Then ,following menu will be displayed:

Enter 1 for  viewing friends of current user
Enter 2 for viewing liked pages
Enter 3 for view the likes of any post you want
Enter 4 if you want to like any post
Enter 5 for viewing timeline liked
Enter 6 for viewing any page
Enter 7 for viewing homepage
Enter 8 to comment on any post
Enter 9 to view any post
Enter 10 to share any post
Enter 11 to search any word in any post you want to find that post
Enter -1 to exit

Hitting 4 to like any post,

command   Like post
Enter post id which you want to like:1

--------------------------------------------------------------

--------------------------------------------------------------

Now if we check for likes of post 1:

we will see that we have liked that post.In similar way we can comment on any post and even search through all the posts through keyword.

and press -1 to exit this program.


That's All! I spent very good time with CS50.

#About CS50
CS50 is a openware course from Havard University and taught by David J. Malan

Introduction to the intellectual enterprises of computer science and the art of programming. This course teaches students how to think algorithmically and solve
problems efficiently.Languages include C, Python, and SQL plus students’ choice of: HTML, CSS, and JavaScript (for web development).

Thanks for CS50.

Where I get [CS50](https://cs50.harvard.edu/x/2021/). course?