/**
*  Database class which contains a list of records.
*
*  Author: Mohammad Ghasembeigi
*
*/

#ifndef DATABASE_H
#define DATABASE_H

// Your database class definition goes here
#include "record.h"

template <class value>
class Database {
public:
  //Default constructor
  Database<value>() : records(list<Record<value>>()), numSelected_(0) {}

  //Member functions

  //Complexity of inlines: O(1)
  inline int numRecords() const { return records.size(); }
  inline int numSelected() const { return numSelected_; }

  void write(ostream& out, DBScope scope) const;
  void read(istream& in);
  void deleteRecords(DBScope scope);
  void selectAll();
  void deselectAll();
  void select(DBSelectOperation selOp, const string& attr, DBQueryOperator op, const value& val);

  //Default Destructor
  ~Database() {};

private:
  list<Record<value>> records;
  int numSelected_;

};

#include "database.tem"

#endif
