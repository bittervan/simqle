#include "../utilities/tuple.hpp"
#include "../utilities/block.hpp"
using namespace std;

int main() {
	string schema_name = "haha";
	string primary_key = "python";
	vector<string> name;
	name.push_back("hello");
	name.push_back("world");
	name.push_back("I");
	name.push_back("love");
	name.push_back("python");

	vector<Type> type;
	type.push_back(Type::INT);
	type.push_back(Type::INT);
	type.push_back(Type::INT);
	type.push_back(Type::DOUBLE);
	type.push_back(Type::STRING);

	vector<int> length;
	length.push_back(sizeof(int));
	length.push_back(sizeof(int));
	length.push_back(sizeof(int));
	length.push_back(sizeof(double));
	length.push_back(sizeof(char) * 100);

	vector<Attribute> attr;
	for (int i = 0; i < type.size(); i++) {
		attr.push_back(Attribute(type[i], length[i]));
	}

	Schema schema(schema_name, name, attr, primary_key);
	// schema._debug_show_info();

	vector<Item> tuple_vals;
	tuple_vals.emplace_back(1);	
	tuple_vals.emplace_back(2);	
	tuple_vals.emplace_back(3);	
	tuple_vals.emplace_back(3.3);
	tuple_vals.emplace_back("foobar");

	Tuple tuple(schema, tuple_vals);
	// tuple._debug_show_info();
	Tuple rebuild(schema, tuple.toBit());
	// rebuild._debug_show_info();
	
	BlockSpecifier specifier("haha", 0);
	cout << schema.toString() << endl;
	cout << Schema(schema.toString()).toString() << endl;
	Block block(schema, specifier);
	block.insertTuple(tuple);
	block.insertTuple(rebuild);
	vector<Requirement> requires;
	// requires.push_back(Requirement("hello", Item(1), Operator::EQ));
	// requires.push_back(Requirement("hello", Item(1), Operator::LE));
	// requires.push_back(Requirement("hello", Item(1), Operator::GT));
	auto result = block.selectTuple(requires);
	cout << "TOTALSIZE: " << result.size() << endl;
	block.deleteTuple(requires);
	result = block.selectTuple(requires);
	cout << "TOTALSIZE: " << result.size() << endl;
	// for (auto i : result) {
	// 	i._debug_show_info();
	// }
}