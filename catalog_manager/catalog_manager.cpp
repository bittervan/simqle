#include "catalog_manager.hpp"
using namespace std;

CatalogManager::CatalogManager(const CatalogManager&) = default;

CatalogManager::CatalogManager(BufferPool& src_buffer): buffer_pool(src_buffer) {}

CatalogManager::~CatalogManager() = default;

void CatalogManager::createTable(const string& src_schema_name, const vector<string>& src_attr_names, const vector<Attribute>& src_attrs, const string& src_primary_key) {
	buffer_pool.createSchema(Schema(src_schema_name, src_attr_names, src_attrs, src_primary_key));
}

void CatalogManager::dropTable(const string& src_schema_name) {
	buffer_pool.dropSchema(src_schema_name);
}

Type CatalogManager::fetchType(const string& src_schema_name, const string& src_attr_name) const {
	return buffer_pool.fetchType(src_schema_name, src_attr_name);
}