#include "../buffer_pool/buffer_pool.hpp"
using namespace std;

class CatalogManager {
	private:
		BufferPool& buffer_pool;
	
	public:
		CatalogManager() = delete;
		CatalogManager(const CatalogManager&);
		CatalogManager(BufferPool&);
		~CatalogManager();

		void createTable(const string&, const vector<string>&, const vector<Attribute>&, const string&);
		void dropTable(const string&);
		Type fetchType(const string&, const string&) const;
};