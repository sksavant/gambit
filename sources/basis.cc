//
// FILE: basis.cc -- Instantiation of Basis class
//
//

#include "basis.h"
#include "gtext.h"

// ---------------------------------------------------------------------------
// Class Basis
// ---------------------------------------------------------------------------

// -----------------------
// C-tor, D-tor, Operators
// -----------------------

Basis::Basis(int first, int last, int firstlabel, int lastlabel)
  : basis(first, last), cols(firstlabel, lastlabel), 
    slacks(first, last), colBlocked(firstlabel,lastlabel),
    rowBlocked(first,last)
{
  int i;
  for(i = cols.First(); i <= cols.Last(); i++) {
    cols[i] = 0;
    colBlocked[i] = false;
  }

  for(i = basis.First(); i <= basis.Last(); i++) {
    basis[i]= - i;
    slacks[i] = i;
    rowBlocked[i] = false;
  }
  IsBasisIdent = true;
}

Basis::Basis(const Basis &bas)
: basis(bas.basis), cols( bas.cols ), slacks( bas.slacks ),
  colBlocked(bas.colBlocked), rowBlocked(bas.rowBlocked), 
  IsBasisIdent(bas.IsBasisIdent)
{ }

Basis::~Basis()
{ }

Basis& Basis::operator=(const Basis &orig)
{
  if(this != &orig) {
    basis = orig.basis; 
    cols = orig.cols;
    slacks = orig.slacks;
    rowBlocked = orig.rowBlocked;
    colBlocked = orig.colBlocked;
    IsBasisIdent = orig.IsBasisIdent;

  }
  return *this;
}

// -------------------------
// Public Members
// -------------------------

int Basis::First() const
{ return basis.First();}

int Basis::Last() const
{ return basis.Last();}

int Basis::MinCol() const
{ return cols.First();}

int Basis::MaxCol() const
{ return cols.Last();}

inline bool Basis::IsRegColumn( int col ) const
{return col >= cols.First() && col <= cols.Last();} 
  
inline bool Basis::IsSlackColumn( int col ) const 
{return  -col >= basis.First() && -col <= basis.Last();} 
  
int Basis::Pivot(int outindex, int col)
{
  int outlabel = basis[outindex];
 
  if (IsSlackColumn(col)) slacks[-col] = outindex;
  else if (IsRegColumn(col)) cols[col] = outindex;
  else throw BadIndex(); // not a valid column to pivot in.
  
  if (IsSlackColumn(outlabel)) slacks[-outlabel] = 0;
  else if (IsRegColumn(outlabel)) cols[outlabel] = 0;
  else {
    // Note: here, should back out outindex.    
    throw BadIndex(); // not a valid column to pivot out. 
  }
  
  basis[outindex] = col;
  CheckBasis();
  
  return outlabel;
}

bool Basis::Member( int col ) const
{
  int ret;

  if (IsSlackColumn(col)) ret = slacks[-col];
  else if (IsRegColumn(col)) ret = cols[col];
  else ret = 0;

  return (ret != 0);
}


int Basis::Find( int col ) const
{
  int ret;

  if ( IsSlackColumn(col)) ret = slacks[-col];
  else if (IsRegColumn(col)) ret = cols[col];
  else throw BadIndex();
  
  return ret;
}

int Basis::Label(int index) const
{
  return  basis[index];
}

void Basis::Mark(int col )
{
  if (IsSlackColumn(col)) rowBlocked[-col] = true;
  else if (IsRegColumn(col)) colBlocked[col] = true;
}

void Basis::UnMark(int col )
{
  if (IsSlackColumn(col)) rowBlocked[-col] = false;
  else if (IsRegColumn(col)) colBlocked[col] = false;
}

bool Basis::IsBlocked(int col) const
{
  if (IsSlackColumn(col)) return rowBlocked[-col];
  else if (IsRegColumn(col)) return colBlocked[col];
  return false;
}

void Basis::CheckBasis() 
{
  bool check = true;

  for (int i =basis.First(); i <= basis.Last() && check; i++)
    if(basis[i] != -i) check = false;
  
  IsBasisIdent = check;
}

bool Basis::IsIdent()
{
  return IsBasisIdent;
}

void Basis::Dump(gOutput &to) const
{ 
  to << "{";
  for(int i=basis.First();i<=basis.Last();i++) 
    to << "  " << basis[i];  
  to << " }";
}

Basis::BadIndex::~BadIndex()
{ }

gText Basis::BadIndex::Description(void) const
{
  return "Bad index in Basis";
}

gOutput &operator<<(gOutput &to, const Basis &v)
{
  v.Dump(to); return to;
}

