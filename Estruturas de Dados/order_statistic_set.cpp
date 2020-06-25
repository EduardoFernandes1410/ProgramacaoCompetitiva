// Coded by @brunomaletta

// Funciona do C++11 pra cima

// Headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// Declaration:
ord_set<int> s;

/******O(log|s|)******/
// iterator to k-th element in set (starts from 0):
s.find_by_order(k);

/******O(log|s|)******/
// number of elements strictly smaller than k:
s.order_of_key(k);


// Multiset (first = element, second = unique id of element)
ord_set<pair<int, int> > ms;

// number of elements strictly smaller than k:
ms.order_of_key({k, -INF});
