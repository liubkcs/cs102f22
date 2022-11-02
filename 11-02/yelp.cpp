#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Address {
private:
  // TODO: street, city, state, zip  
};

class Restaurant {
public:
  void SetName(string);
  void SetGeoCoord(double lat, double lon);
  void AddRating(int);
  double GetAverageRating();
  void Print();
private:
  string name;
  Address address;
  double lat, lon;
  vector<int> ratings;
  double cachedAverageRating;
};

void Restaurant::SetName(string theName) {
	name = theName;
}

void Restaurant::AddRating(int num) {
	ratings.push_back(num);
	double sum = 0;
	for(int rating : ratings) {
		sum += rating;
	}
	cachedAverageRating = sum / ratings.size();
}

void Restaurant::Print() {
	cout << name << " -- " << GetAverageRating()
       << endl;
}

double Restaurant::GetAverageRating() {
	return cachedAverageRating;
}
int main()
{
	Restaurant lunchPlace;
	lunchPlace.SetName("Smashburger");
	lunchPlace.AddRating(5);
	lunchPlace.AddRating(4);
	lunchPlace.Print();
	return 0;}
