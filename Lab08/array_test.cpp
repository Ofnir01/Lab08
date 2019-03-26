#include "catch.hpp"
#include "array.h"
#include <string>
#include <iostream>
#include <sstream>
using std::string;

TEST_CASE("Testing array.h") {
	SECTION("Testing default constructor") {
		Array<short> test;
		REQUIRE(test.getCapacity() == 1);
		REQUIRE(test.getSize() == 0);

		Array<string> test2;
		REQUIRE(test.getCapacity() == 1);
		REQUIRE(test.getSize() == 0);
	}

	SECTION("Testing explicit value constructor") {
		Array<short> test(10);
		REQUIRE(test.getCapacity() == 10);
		REQUIRE(test.getSize() == 0);
		
		Array<string> test2(10);
		REQUIRE(test.getCapacity() == 10);
		REQUIRE(test.getSize() == 0);
	}

	SECTION("Testing [] overload") {
		Array<string> test(1);
		test.append("Hello");
		test.append("There!");
		test.append("How");
		test.append("are");
		test.append("you?");
		REQUIRE(test[0] == "Hello");
		REQUIRE(test[1] == "There!");
		REQUIRE(test[2] == "How");
		REQUIRE(test[4] == "you?");

		Array<short> test2(1);
		test2.append(1);
		test2.append(2);
		test2.append(3);
		test2.append(4);
		test2.append(5);
		REQUIRE(test2[0] == 1);
		REQUIRE(test2[1] == 2);
		REQUIRE(test2[2] == 3);
		REQUIRE(test2[4] == 5);
	}

	//The append and pop functions where testted together becuase of the similarity and correlation that
	//they have.
	SECTION("Testing append and pop functions") {
		Array<string> test(1);
		test.append("Hello");
		REQUIRE(test[0] == "Hello");
		REQUIRE(test.getSize() == 1);

		test.append(" There");
		REQUIRE(test[1] == " There");
		REQUIRE(test.getCapacity() == 2);
		REQUIRE(test.getSize() == 2);

		test.append("!");
		REQUIRE(test[2] == "!");
		REQUIRE(test.getCapacity() == 4);
		REQUIRE(test.getSize() == 3);

		test.append("!");
		REQUIRE(test[3] == "!");
		REQUIRE(test.getCapacity() == 4);
		REQUIRE(test.getSize() == 4);

		test.append("!");
		REQUIRE(test[3] == "!");
		REQUIRE(test.getCapacity() == 8);
		REQUIRE(test.getSize() == 5);

		test.pop();
		REQUIRE(test.getCapacity() == 8);
		REQUIRE(test.getSize() == 4);

		test.pop();
		REQUIRE(test.getCapacity() == 8);
		REQUIRE(test.getSize() == 3);

		test.pop();
		REQUIRE(test.getCapacity() == 8);
		REQUIRE(test.getSize() == 2);

		test.pop();
		REQUIRE(test.getCapacity() == 4);
		REQUIRE(test.getSize() == 1);

		Array<short> test2(1);
		test2.append(1);
		REQUIRE(test2[0] == 1);
		REQUIRE(test2.getSize() == 1);

		test2.append(2);
		REQUIRE(test2[1] == 2);
		REQUIRE(test2.getCapacity() == 2);
		REQUIRE(test2.getSize() == 2);

		test2.append(3);
		REQUIRE(test2[2] == 3);
		REQUIRE(test2.getCapacity() == 4);
		REQUIRE(test2.getSize() == 3);

		test2.append(4);
		REQUIRE(test2[3] == 4);
		REQUIRE(test2.getCapacity() == 4);
		REQUIRE(test2.getSize() == 4);

		test2.append(5);
		REQUIRE(test2[4] == 5);
		REQUIRE(test2.getCapacity() == 8);
		REQUIRE(test2.getSize() == 5);

		test2.pop();
		REQUIRE(test2.getCapacity() == 8);
		REQUIRE(test2.getSize() == 4);

		test2.pop();
		REQUIRE(test2.getCapacity() == 8);
		REQUIRE(test2.getSize() == 3);

		test2.pop();
		REQUIRE(test2.getCapacity() == 8);
		REQUIRE(test2.getSize() == 2);

		test2.pop();
		REQUIRE(test2.getCapacity() == 4);
		REQUIRE(test2.getSize() == 1);
	}

	
	SECTION("Testing << overload") {
		Array<short> test(1);
		test.append(1);
		test.append(2);
		test.append(3);
		test.append(4);
		test.append(5);

		std::ostringstream out;
		out << test;

		REQUIRE(out.str() == "{ 1, 2, 3, 4, 5 }");

		Array<string> test2(1);
		test2.append("A");
		test2.append("B");
		test2.append("C");
		test2.append("D");
		test2.append("E");

		std::ostringstream out2;
		out2 << test2;

		REQUIRE(out2.str() == "{ A, B, C, D, E }");
	}

	SECTION("Testing subscript exceptions") {
		Array<short> test;
		REQUIRE_THROWS_AS(test[2], SubscriptException);

		Array<string> test2;
		REQUIRE_THROWS_AS(test2[-1], SubscriptException);
	}

	SECTION("Testing memory exceptions") {
		//I didn't knew how to make test cases for this exception
		//becuase even if I repeat the the same process of the exceptions lab
		//I will still get compiler errors.
	}
}