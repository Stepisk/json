#include <boost/nowide/iostream.hpp>
#include <boost/nowide/args.hpp>
#include <boost/json.hpp>
#include <fstream>

boost::json::value read_json(std::istream& is, boost::json::error_code& ec) {
	boost::json::stream_parser p;
	std::string line;
	while (std::getline(is, line)) {
		p.write(line, ec);
		if (ec)
			return nullptr;
	}
	p.finish(ec);
	if (ec)
		return nullptr;
	return p.release();
}

int main(int argc, char* argv[]) {
	boost::nowide::args _(argc, argv);
	
	// JSON object
	boost::json::object obj;
	obj["pi"] = 3.141;
	obj["happy"] = true;
	obj["name"] = "Boost";
	obj["nothing"] = nullptr;
	obj["answer"].emplace_object()["everything"] = 42;
	obj["list"] = { 1, 0, 2 };
	obj["object"] = { {"currency", "USD"}, {"value", 42.99} };

	// JSON object to string
	std::string s = boost::json::serialize(obj);
	boost::nowide::cout << s << std::endl << std::endl;

	// JSON array
	boost::json::array arr = { true, "text", 4.53, 5 };
	for (const boost::json::value& val : arr) {
		boost::nowide::cout << val << std::endl;
	}
	boost::nowide::cout << std::endl;

	// Read JSON from file
	std::ifstream fin("D:\\test.json");
	if (fin.is_open()) {
		boost::json::error_code ec;
		boost::json::object o = read_json(fin, ec).as_object();
		if (!ec) {
			boost::nowide::cout << "Object: " << o << std::endl << std::endl;

			boost::nowide::cout << "Keys:" << std::endl;
			for (const boost::json::object::value_type& vt : o) {
				boost::nowide::cout << vt.key() << ": " << vt.value() << std::endl;
			}
		}
		else {
			boost::nowide::cout << "Error parse file! " << ec << std::endl;
		}

		fin.close();
	}

	return 0;
}
