//priority queue by default is a maximum heap

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    // Naive - but not easy - Solution
    // int n = (int)A.size();

    // vector<pair<int,pair<int,int>>>allPairs;
    // for(int a:A)
    //     for(int b:B)
    //         allPairs.push_back(make_pair(-(a+b), make_pair(a,b)));
    // priority_queue<pair<int,pair<int,int>>>pq;
    // for(pair<int,pair<int,int>> pair:allPairs)
    //     if(pq.size()<n)
    //         pq.push(pair);
    //     else if(pq.top().first>pair.first){
    //         pq.pop();
    //         pq.push(pair);
    //     }
    // vector<int>response;
    // while(!pq.empty()){
    //     response.push_back(-pq.top().first);
    //     pq.pop();
    // }
    // int size = (int)response.size();
    // for(int i=0;i<size/2;i++)
    //     swap(response[i], response[size-i-1]);
    // return response;

    vector<int>response;
    sort(A.begin(), A.end(), [](const int& a, const int& b){
      return a > b;
    });
    sort(B.begin(), B.end(), [](const int& a, const int& b){
      return a > b;
    });
    priority_queue<pair<int,pair<int,int>>>pq;
    int i=0,j=0,ii,jj;
    pq.push(make_pair(A[i]+B[j], make_pair(i,j)));

    set<pair<int,int>>mapset;
    mapset.insert(make_pair(i,j));

    int qty = (int)A.size(), size = (int)A.size();
    while(qty--){
        pair<int,pair<int,int>> top = pq.top();
        pq.pop();
        i = top.second.first;
        j = top.second.second;
        response.push_back(top.first);

        ii=i;jj=j+1;
        if(ii < size && jj < size && mapset.find(make_pair(ii,jj)) == mapset.end()){
          pq.push(make_pair(A[ii]+B[jj], make_pair(ii,jj)));
          mapset.insert(make_pair(ii,jj));
        }
        ii=i+1;jj=j;
        if(ii < size && jj < size && mapset.find(make_pair(ii,jj)) == mapset.end()){
          pq.push(make_pair(A[ii]+B[jj], make_pair(ii,jj)));
          mapset.insert(make_pair(ii,jj));
        }
    }
    return response;
}
