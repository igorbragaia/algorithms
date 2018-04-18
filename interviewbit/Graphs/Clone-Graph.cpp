/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 UndirectedGraphNode *clone(UndirectedGraphNode * root, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>&hashmap){
 	if(hashmap.find(root) != hashmap.end()){
 		return hashmap[root];
 	}
 	else {
 	    if(root != NULL){
      		UndirectedGraphNode *newroot = new UndirectedGraphNode(root->label);
      		hashmap[root] = newroot;
     		for(UndirectedGraphNode *neighbor:root->neighbors){
     			newroot->neighbors.push_back(clone(neighbor, hashmap));
     		}
     		return newroot;
 	    } else {
 	        return hashmap[root] = NULL;
 	    }
 	}
 }
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
	unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> hashmap;
	return clone(node, hashmap);
}
