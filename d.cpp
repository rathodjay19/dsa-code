// TREE

--> GET PATH FROM NODE A TO NODE B

        vector<int>
            bobPath(n, -1);
vector<int> path;

function<bool(int, int)> findPath = [&](int node, int parent)
{
    if (node == DEST_NODE)
        return true;

    for (int neighbor : graph[node])
    {
        if (neighbor != parent)
        {
            path.push_back(node);
            if (findPath(neighbor, node))
                return true;
            path.pop_back();
        }
    }
    return false;
};

findPath(SRC_NODE, -1);
for (int i = 0; i < path.size(); i++)
{
    bobPath[path[i]] = i;
}