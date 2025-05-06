#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fibonacci.hpp"
#include "palindrome.hpp"
#include "linkedlist.hpp"

TEST_CASE("generateFibonacci works correctly", "[fibonacci]") {
    REQUIRE_THROWS_AS(generateFibonacci(0), std::invalid_argument);
    auto fib5 = generateFibonacci(5);
    REQUIRE(fib5 == std::vector<unsigned long long>{0, 1, 1, 2, 3});
}

TEST_CASE("isPalindrome works correctly", "[palindrome]") {
    REQUIRE_THROWS_AS(isPalindrome(-121), std::invalid_argument);
    REQUIRE(isPalindrome(121) == true);
    REQUIRE(isPalindrome(123) == false);
    REQUIRE(isPalindrome(0) == true);
}

TEST_CASE("reverseList works correctly", "[linkedlist]") {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;

    ListNode* reversed = reverseList(n1);
    REQUIRE(reversed->val == 3);
    REQUIRE(reversed->next->val == 2);
    REQUIRE(reversed->next->next->val == 1);
    REQUIRE(reversed->next->next->next == nullptr);

    delete reversed->next->next;
    delete reversed->next;
    delete reversed;
}
