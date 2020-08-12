#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that ill be stored in the MovieTree BST

MovieTree::MovieTree()
{
  //write your code
  root = NULL;
}

/*
void destroyNode(MovieNode *currNode)
{

    if (currNode != NULL)
    {
      destroyNode(currNode->left);
      destroyNode(currNode->right);

      delete currNode;
      currNode = NULL;
    }
}
*/

MovieTree::~MovieTree()
{
  //maybe this should just be: delete root;
  //thats what was in kyle's code
  // destroyNode(root);
  delete root;
}

void printMovieHelper(MovieNode *currNode)
{
  if (currNode)
  {
    printMovieHelper(currNode->left);
    cout << "Movie: " << currNode->title << " " << currNode->rating << endl;
    printMovieHelper(currNode->right);
  }
  else
  {
    return;
  }
  // might need else statement with return in it
}

void MovieTree::printMovieInventory()
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    printMovieHelper(root);
  }
}

MovieNode *createNode(string titleData, int numRank, int yearNum, float ratingNum)
{
  MovieNode *newNode = new MovieNode(numRank, titleData, yearNum, ratingNum); // = new MovieNode; //this line probably has some problems
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

MovieNode *addNodeHelper(MovieNode *currNode, string titleData, int numRank, int yearNum, float ratingNum)
{
  if (currNode == NULL)
  {
    return createNode(titleData, numRank, yearNum, ratingNum);
  }

  else if (currNode->title.compare(titleData) < 0)
  {
    currNode->right = addNodeHelper(currNode->right, titleData, numRank, yearNum, ratingNum);
  }
  
  else if (currNode->title.compare(titleData) > 0)
  {
    currNode->left = addNodeHelper(currNode->left, titleData, numRank, yearNum, ratingNum);
  }
  return currNode;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{
  root = addNodeHelper(root, title, ranking, year, rating);
}

MovieNode *searchHelper(MovieNode *currNode, string titleData)
{
  if (currNode == NULL)
  {
    return NULL;
  }

  if (currNode->title == titleData)
  {
    return currNode;
  }
  
  if (currNode->title.compare(titleData) > 0)
  {
    return searchHelper(currNode->left, titleData);
  }
  
  if (currNode->title.compare(titleData) < 0)
  {
    return searchHelper(currNode->right, titleData);
  }

}

void MovieTree::findMovie(string title)
{
  MovieNode *temp = searchHelper(root, title);
  if (temp != NULL)
  {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << temp->ranking << endl;
    cout << "Title  :" << temp->title << endl;
    cout << "Year   :" << temp->year << endl;
    cout << "Rating :" << temp->rating << endl;
  }
  else
  {
    cout << "Movie not found." << endl;
  }
}

void queryHelper(MovieNode *currNode, float rating, int year)
{
  if (currNode == NULL)
  {
    return;
  }
  else
  {
    if (currNode->rating >= rating && currNode->year > year)
    {
      cout << currNode->title << "(" << currNode->year << ") " << currNode->rating << endl;
    }
    queryHelper(currNode->left, rating, year);
    queryHelper(currNode->right, rating, year);
  }
}

void MovieTree::queryMovies(float rating, int year)
{
  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryHelper(root, rating, year);
  }
}

float recursionSum(MovieNode *node, float sum)
{
  if (node == NULL)
  {
    return sum;
  }
  else
  {
    sum += node->rating;
    sum = recursionSum(node->left, sum);
    sum = recursionSum(node->right, sum);
  }
  return sum;
}

int recursionCount(MovieNode *node, int count)
{
  if (node == NULL)
  {
    return count;
  }
  else
  {
    count++;
    count = recursionCount(node->left, count);
    count = recursionCount(node->right, count);
  }
  return count;
}

void MovieTree::averageRating()
{
  int count = 0;
  int sum = 0;
  if (root != NULL)
  {
    int numMovies = recursionCount(root, count);
    float ratingSum = recursionSum(root, sum);
    float avg = ratingSum / numMovies;
    cout << "Average rating:" << avg << endl;
    return;
  }
  else
  {
    cout << "Average rating:0.0" << endl;
  }
}