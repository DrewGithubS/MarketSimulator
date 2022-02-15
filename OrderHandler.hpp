#include <SortedList.hpp>

class OrderHandler {
public:
	void addOrder(Order order);
	void cancelOrder();
private:
	SortedList * sellList<long, true>;
	SortedList * buyList<long, false>;
}