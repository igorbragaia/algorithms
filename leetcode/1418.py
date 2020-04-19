class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        hashmap = {}
        tables = []
        plates = []
        for order in orders:
            if order[1] not in tables:
                tables.append(order[1])
            if order[2] not in plates:
                plates.append(order[2])
                
            if order[1] not in hashmap:
                hashmap[order[1]] = {}
            if order[2] not in hashmap[order[1]]:
                hashmap[order[1]][order[2]] = 0
            
            hashmap[order[1]][order[2]] += 1
        
        tables = sorted(tables)
        plates = sorted(plates)
        
        rows = []
        for table in tables:
            tmp = [int(table)]
            for plate in plates:
                if plate in hashmap[table]:
                    tmp.append(hashmap[table][plate])
                else:
                    tmp.append(0)
            rows.append(tmp)
        rows = sorted(rows)
        response = [["Table"] + plates ]
        for row in rows:
            tmp = []
            for el in row:
                tmp.append(str(el))
            response.append(tmp)
        return response
