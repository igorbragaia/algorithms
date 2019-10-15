# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""

        arr = [{"val": root.val, "parent_i": None, "side": None}]
        q = collections.deque()
        q.appendleft([root, 0])
        while q:
            f, i = q.pop()
            if f.left is not None:
                q.appendleft([f.left, len(arr)])
                arr.append({"val": f.left.val, "parent_i": i, "side": "left" })
            if f.right is not None:
                q.appendleft([f.right, len(arr)])
                arr.append({"val": f.right.val, "parent_i": i, "side": "right" })

        response = [{"val": node["val"], "left_i": None, "right_i": None} for node in arr]
        for i in range(1, len(arr)):
            if arr[i]["side"] == "left":
                response[arr[i]["parent_i"]]["left_i"] = i
            elif arr[i]["side"] == "right":
                response[arr[i]["parent_i"]]["right_i"] = i

        return "|".join(["{0},{1},{2}".format(node["val"], node["left_i"], node["right_i"]) for node in response])

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None

        nodes = [node.split(",") for node in data.split("|")] # [val, left i, right i]
        nodes = [{"node": TreeNode(node[0]), "left_i": node[1], "right_i": node[2]} for node in nodes]

        root = nodes[0]

        q = collections.deque()
        q.appendleft(root)
        while q:
            f = q.pop()
            if f["left_i"] != "None":
                i = int(f["left_i"])
                f["node"].left = nodes[i]["node"]
                q.appendleft(nodes[i])
            if f["right_i"] != "None":
                i = int(f["right_i"])
                f["node"].right = nodes[i]["node"]
                q.appendleft(nodes[i])

        return root["node"]
 




# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))