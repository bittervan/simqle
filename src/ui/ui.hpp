#pragma once
#include "../record_manager/record_manager.hpp"
#include "../catalog_manager/catalog_manager.hpp"
using namespace std;

class UI {
	public:
		UI();
		~UI();
		string fetchStatement() const;
		void plotTable(const vector<string>&, const vector<Type>&, const vector<int>&, const vector<Tuple>&, const vector<string>&) const;
};