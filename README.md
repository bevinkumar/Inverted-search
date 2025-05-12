Overview
The Inverted Search project is an implementation of an efficient text search algorithm using Data Structures and Algorithms (DSA). It involves building an inverted index, which is a data structure used to store a mapping from content (words or terms) to their locations within a document or set of documents. The goal of this project is to efficiently search for words and retrieve their positions within a set of documents.

In this project, we’ll use hash tables (for fast retrieval) and linked lists (to maintain document positions) as the primary data structures. The inverted index can be used for keyword-based searching, which is useful for applications like search engines, document retrieval systems, or even text-based databases.

Features
Inverted Index Construction: Build an inverted index for a collection of documents.

Search Query: Allow users to search for a word and retrieve the documents where the word appears.

Efficient Storage and Retrieval: Use hash tables for fast insertion and retrieval of words and their document positions.

Support for Multiple Documents: The project can handle multiple documents, each identified by an index or name.

Key Concepts
Inverted Index
An inverted index is a mapping of each word (or term) in a document collection to a list of locations where it appears. These locations can be:

The document in which the word appears.

The position of the word within the document.

Hash Tables
A hash table is used to store words as keys and their locations (document indices and positions) as values. Hash tables allow fast lookup, insertion, and deletion operations in average constant time 
𝑂
(
1
)
O(1).

Linked Lists
For each word in the inverted index, a linked list is used to store the positions of the word in different documents. The linked list allows us to efficiently store and manage the positions of each word in various documents.

Steps in the Inverted Search Process
Index Creation:

For each document, tokenize the words.

For each word, store its document ID and position in a hash table.

If a word already exists in the hash table, add the document ID and position to the existing linked list.

Search Query:

Take a user input word and check if it exists in the hash table.

If the word exists, retrieve the linked list of document positions.

Print the documents and positions where the word appears.
