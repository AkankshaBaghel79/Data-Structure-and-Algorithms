#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
    int contentquality;
public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
        contentquality = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}

    void checkanalytics()
    {
        if(contentquality < 5)
        {
            cout<<Name<<" has a bad quality"<<endl;
        }
        else{
            cout<<Name<<" has a good quality"<<endl;
        }
    }
};

class CookingYouTubeChannel :public YouTubeChannel {
public:
	CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {

	}
	void Practice() {
		cout << OwnerName << " is taking singing classes, practicising vocals cords,...learning how to dance" << endl;
        contentquality++;
	}
};

class SingerYouTubeChannel :public YouTubeChannel {
public:
	SingerYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {

	}
	void Practice() {
		cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        contentquality++;
	}
};
 
int main()
{
	CookingYouTubeChannel cookingYouTubeChannel("Amy's Kitchen", "Amy");
	SingerYouTubeChannel singingYouTubeChannel("Taylor's swift", "warner");

    cookingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();
    singingYouTubeChannel.Practice();


    YouTubeChannel* yt1 = &cookingYouTubeChannel;
    YouTubeChannel* yt2 = &singingYouTubeChannel;

    yt1->checkanalytics();
    yt2->checkanalytics();


	system("pause>0");
}