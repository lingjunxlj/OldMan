#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct node
{
	vector<struct node *> children;
	bool visited;
	bool home;
};
typedef struct node node_t;

static void add_neighbor(node_t *p, node_t *n)
{
	bool add = true;

	for (vector<node_t *>::iterator i = p->children.begin();
		i != p->children.end(); ++i)
	{
		// Don't add if it's a duplicate
		if (*i == n || p == n)
		{
			add = false;
			break;
		}
	}

	if (add)
		p->children.push_back(n);
}

static void destroy_state(vector<node_t *> state)
{
	for (vector<node_t *>::iterator i = state.begin();
		i != state.end();
		++i)
	{
		delete *i;
		*i = NULL;
	}
}

// Recursive function to find a path to the "home" node while only
// traversing each point once.  Returns a boolean indicating whether
// or not this is possible.
static bool can_walk(node_t *node, int depth, int maxdepth)
{
	bool retval = false;

	node->visited = true;

	// Walk through each unvisited child until home is found or we
	// get stuck.
	for (vector<node_t *>::iterator i = node->children.begin();
		i != node->children.end();
		++i)
	{
		// If we have traversed all points and hit home, we're done.
		if (depth == maxdepth && (*i)->home)
		{
			retval = true;
			break;
		}

		// Skip home and points we've already visited.
		if ((*i)->home || (*i)->visited)
			continue;

		// If this node leads to a valid exit, we're done.
		if (can_walk(*i, depth + 1, maxdepth))
		{
			retval = true;
			break;
		}
	}

	node->visited = false;

	return retval;
}

int main(void)
{
	int n;
	int c = 0;

	while (cin >> n && n != 0)
	{
		string l;
		getline(cin, l);

		vector<node_t *> places;

		// Initialize core points
		for (int i = 0; i <= n; ++i)
		{
			node_t *p = new node_t;
			p->visited = false;
			if (!i)
				p->home = true;
			places.push_back(p);
		}

		// Link points together
		for (int i = 1; i <= n; ++i)
		{
			string line;
			stringstream s;
			getline(cin, line);
			s << line;

			int p;

			while (s >> p)
			{
				add_neighbor(places[i], places[p]);
				add_neighbor(places[p], places[i]);
			}
		}

		++c;
		cout << "Case " << c << ": ";
		if (can_walk(places[0], 0, n))
			cout << "Granny can make the circuit." << endl;
		else
			cout << "Granny can not make the circuit." << endl;

		destroy_state(places);
	}

	return 0;
}
