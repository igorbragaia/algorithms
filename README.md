# System Design Notes

## How to approach a problem?

* **Features** expectations
* **Estimations** (scale required, database sharding, caching, load balancing, etc)
* **Design goals** (latency required, CAP - consistency, availability and partitioning, ACID SQL properties - atomicity, consistency, isolation and durability, BASE NoSQL properties - basic availability, soft-state and eventual consistency)
* **Skeleton** of the Design
* **Deep dive** into above statements - API endpoints, client requirements, if sharding, how to consistent hash, security, randomness, etc

### The CAP Theorem

Published by Eric Brewer in 2000, the theorem is a set of basic requirements that describe any distributed system. If you imagine a distributed database system with multiple servers, here's how the CAP theorem applies:
* **Consistency** - All the servers in the system will have the same data so users will get the same copy regardless of which server answers their request.
* **Availability** - The system will always respond to a request (even if it's not the latest data or consistent across the system or just a message saying the system isn't working).
* **Partition Tolerance** - The system continues to operate as a whole even if individual servers fail or can't be reached.

It's theoretically impossible to have all 3 requirements met, so a combination of 2 must be chosen and this is usually the deciding factor in what technology is used.

When it comes to distributed databases, the two choices are only AP or CP because if it's not partition tolerant, it's not really a reliable distributed database. So the choice is simpler: if a network split happens, do you want the database to keep answering but with possibly old/bad data (AP)? Or should it just stop responding unless you can get the absolute latest copy (CP)?

### ACID

This describes a set of properties that apply to data transactions, defined as follows:
* **Atomicity** - Everything in a transaction must happen successfully or none of the changes are committed. This avoids a transaction that changes multiple pieces of data from failing halfway and only making a few changes.
* **Consistency** - The data will only be committed if it passes all the rules in place in the database (ie: data types, triggers, constraints, etc).
* **Isolation** - Transactions won't affect other transactions by changing data that another operation is counting on; and other users won't see partial results of a transaction in progress (depending on isolation mode).
* **Durability** - Once data is committed, it is durably stored and safe against errors, crashes or any other (software) malfunctions within the database.

### SQL / Relational DB

ACID is commonly provided by most classic relational databases like MySQL, Microsoft MS SQL Server (product), Oracle (company) and others. These are known for storing data in spreadsheet-like tables that have their columns and data types strictly defined. The tables can have relationships between each other and the data is queried with SQL (Structured Query Language), which is a standardized language for working with databases - and why these are also commonly called "SQL databases".

### NoSQL

With the massive amounts of data being created by modern companies, alternative databases have been developed to deal with the scaling and performance issues of existing systems as well as be a better fit for the kind of data created. NoSQL databases are what these alternatives are grouped under because many do not support SQL as a way to query the data, although this is a poor term.

These alternatives have matured now and while some do provide SQL abilities, they have come to be known more for their emphasis on scalable storage of a much higher magnitude of data (ie: terabytes and petabytes) by dropping support for database joins, storing data differently and using several distributed servers together as one. They also tend to not have ACID support to make transactions faster and easier to scale.

### Tying it all together

CAP provides the basic requirements that a distributed system must follow and ACID is a set of rules that a database can choose to follow that guarantees how it handles transactions and keeps data safe.

There are lots of options other than relational databases for storing more or different kinds of data and they often use a distributed set of servers working together and are designed either for AP or CP under the CAP theorem. When it comes to how safe the committed data is, any ACID compliant system can be considered reliable.

Final note: There really is no such thing as "NoSQL" - it's just a meaningless term that caught on and it's far better to just reference the type of database itself:
* Relational (mysql, oracle, sql server, postgres)
* Document Store (mongodb, riak, couchbase, rethinkdb)
* Key/Value (redis, aerospike, leveldb)
* Wide-Column (different from relational db with columnar storage and really more like nested-key/value: hbase, cassandra)
* Graph (neo4j, titan)
* Search (optimized for storing and searching against text, elasticsearch, solr, lucene)

## SQL Storage Scalability

* Replication Master-Slave

![alt text](https://raw.githubusercontent.com/igorbragaia/algorithms/e0329f7c64dfd13b55208e6b964bbd321908703a/interviewbit/System-Design-notes/replication-master-slave.png)

* Replication Master-Master

![alt text](https://raw.githubusercontent.com/igorbragaia/algorithms/e0329f7c64dfd13b55208e6b964bbd321908703a/interviewbit/System-Design-notes/replication-master-master.png)

* Load Balancer

![alt text](https://raw.githubusercontent.com/igorbragaia/algorithms/e0329f7c64dfd13b55208e6b964bbd321908703a/interviewbit/System-Design-notes/load-balancer.png)

* Load Balancer + Replication

![alt text](https://raw.githubusercontent.com/igorbragaia/algorithms/e0329f7c64dfd13b55208e6b964bbd321908703a/interviewbit/System-Design-notes/load-balancing%2Breplication.png)

* Load Balancer + Replication + Partitioning

![alt text](https://raw.githubusercontent.com/igorbragaia/algorithms/e0329f7c64dfd13b55208e6b964bbd321908703a/interviewbit/System-Design-notes/load-balancing%2Breplication%2Bpartitioning.png)


<!-- https://www.palantir.com/library/
https://www.youtube.com/watch?v=QwoCgLvoUvs
https://www.youtube.com/watch?v=U0xTu6E2CT8
https://www.quora.com/What-is-the-relation-between-SQL-NoSQL-the-CAP-theorem-and-ACID
https://neo4j.com/blog/acid-vs-base-consistency-models-explained/
https://www.johndcook.com/blog/2009/07/06/brewer-cap-theorem-base/
https://www.youtube.com/watch?v=r8RxkpUvxK0
https://www.youtube.com/watch?v=NjpEZBTCML8
https://www.youtube.com/watch?v=jItLuOTsCX4
https://www.interviewcake.com/cpp-interview-questions
///
https://www.youtube.com/channel/UCAjsH3UCJrd-xAfUBsB-dOg/videos

zookeeper? -->
