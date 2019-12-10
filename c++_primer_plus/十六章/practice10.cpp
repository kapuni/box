//vect3.cpp -- using  STL function
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;
struct Review
{
    std::string title;
    int rating;
    double price;
};
//÷«ƒ‹÷∏’Î
bool operator<(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool FillReview(Review &rr);
void ShowReview(const shared_ptr<Review> & rr);
void showmenu();
bool sorting1(const shared_ptr<Review> & r1,const shared_ptr<Review> & r2);

int main ()
{


    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
    {
		shared_ptr<Review> pd_temp(new Review(temp));
        books.push_back(pd_temp);
    }

	if (books.size() > 0)
	{
		cout << "choose a way to show data.";
		int choice;
		showmenu();
		cin >> choice;
		while (choice <= 7 && choice > 0)
		{
			switch (choice)
			{
			case 1:
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 2:
				sort(books.begin(), books.end());
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 3:
				sort(books.begin(), books.end(), worseThan);
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 4:
				sort(books.begin(), books.end(), worseThan);
				reverse(books.begin(), books.end());
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 5:
				sort(books.begin(), books.end(), sorting1);
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 6:
				sort(books.begin(), books.end(), sorting1);
				reverse(books.begin(), books.end());
				for_each(books.begin(), books.end(), ShowReview);
				break;
			default:
				cout << "wrong number.";
				continue;
			}
			showmenu();
			cin >> choice;
		}
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	// cin.get();
	return 0;
}


bool operator <(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if(r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> &r2)
{
    if(r1->rating <r2->rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >>rr.rating;
    cout << "Enter book price:";
    cin >> rr.price;
    if (!std::cin)
        return false;

    //get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
    cout << "name\trating\tprice\n";
    std::cout << rr->title<<"\t"<< rr->rating << "\t" << rr->price  << std::endl;
}

bool sorting1(const shared_ptr<Review> & r1,const shared_ptr<Review> &r2)
{
    if(r1->price< r2->price)
        return true;
    if (r1->price == r2->price && r1-> rating < r2->rating)
        return true;
    else
        return false;
}

void showmenu()
{
    cout <<"Please enter 1,2,3,4,5,6,pr 7:\n"
        <<"1) by original order   \t2)by alphabet order \n"
        << "3) by rating up        \t4) by rating down \n"
        << "5) by pricing up       \t6) by pricing down \n"
        << "7) quit \n";
}
