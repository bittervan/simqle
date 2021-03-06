#pragma once
#include "../utilities/block.hpp"
using namespace std;

class BufferPool {
	private:
		unordered_map<BlockSpecifier, Block> block_map;
		list<BlockSpecifier> unpinned_list;		
		unordered_map<string, Schema> schema_map;

	public:
		BufferPool();
		~BufferPool();
		BufferPool(const BufferPool&) = delete;

		Block& operator[](const BlockSpecifier&);
		const Schema& operator[](const string&) const;
		void pinBlock(const BlockSpecifier&);
		void unpinBlock(const BlockSpecifier&);
		void dropSchema(const string&);
		void createSchema(const Schema&);
		int schemaBlockNumber(const string&) const;
		void _debug_show_info() const;
		Type fetchType(const string&, const string&) const;
		int fetchLength(const string&, const string&) const;
		Block& fetchNew(const string&);
		vector<Tuple> directFetch(const vector<TupleSpecifier>&);

		unordered_map<string, list<int>> free_list;
		unordered_map<string, unordered_map<Item, int>> duplicant_map;
		unordered_set<string> schema_set;
		unordered_set<string> index_set;
};