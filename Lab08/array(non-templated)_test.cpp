#include "catch.hpp"
#include "array(non-templated).h"
#include <string>
#include <iostream>
#include <sstream>

TEST_CASE("Testing array.h") {
	SECTION("Testing default constructor"){
		Array test;
		REQUIRE(test.getCapacity() == 1);
		REQUIRE(test.getSize() == 0);
	}

	SECTION("Testing explicit value constructor") {
		Array test(10);
		REQUIRE(test.getCapacity() == 10);
		REQUIRE(test.getSize() == 0);
	}

	SECTION("Testing [] overload") {
		Array test(1);
		test.append("Hello");
		test.append("There!");
		test.append("How");
		test.append("are");
		test.append("you?");

		REQUIRE(test[0] == "Hello");
		REQUIRE(test[1] == "There!");
		REQUIRE(test[2] == "How");
		REQUIRE(test[4] == "you?");
	}

	//The append and pop functions where testted together becuase of the similarity and correlation that
	//they have.
	SECTION("Testing append and pop functions") {
		Array test(1);
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
	}

	/*
	SECTION("Testing << overload") {
		Array test(1);
		test.append("Hello ");
		test.append("There! ");
		test.append("How ");
		test.append("are ");
		test.append("you?");
		
		std::ostringstream out;
		out << test;

		REQUIRE(out == "Hello There! How are you?");
	}
	*/
}