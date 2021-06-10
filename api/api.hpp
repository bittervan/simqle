#pragma once
#include <vector>
using namespace std;

// The programming interface
// Declared by Wang Yiming
// Modified by BitteVan
class API {
	private:
		CatalogManager& catalog_manager;
		// IndexManager& index_manager;
		RecordManager& record_manager;

	public:
		API(CatalogManager&, RecordManager&);
		~API();

		// @brief: 获取容器迭代器
		// @param: void
		// @ret: 返回容器迭代器
		// @birth: created by Dablelv on 20180802
		void createTable(const string&, const vector<Attribute>&, const string&);
		void dropTable(const string&);
		void createIndex(const string&, const string&, const string&);
		void dropIndex(const string&);
		void selectTuple(const string&, const vector<Requirement>&);
		void insertTuple(const string&, const vector<string>&)
		void deleteTuple(const string&, const vector<Requirement>&);
}