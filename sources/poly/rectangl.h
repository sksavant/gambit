//
// FILE: rectangl.h -- gRectangle class
//
// $Id$ 
//

#ifndef RECTANGL_H
#define RECTANGL_H

#include "base/odometer.h"
#include "interval.h"
#include "math/gvector.h"

/* This file provides the template class

   gRectangle

which models the concept of a nonempty compact interval.
Since boundary points can be identified, open and half 
open (bounded) intervals can be effected, but less directly.
*/

template <class T> class gRectangle {
private:
    gList<gInterval<T> > sides;

public:
    // constructors
    gRectangle(const gRectangle<T>&);
    gRectangle(const gList<gInterval<T> >&);
    gRectangle(const gVector<T>, const gVector<T>);
    ~gRectangle();

    // operators
    gRectangle<T>& operator =  (const gRectangle<T>& y);
    bool          operator == (const gRectangle<T>& y) const;
    bool          operator != (const gRectangle<T>& y) const;

    // information
    const int                Dmnsn()                            const;
    gVector<T>         LowerBound()                       const;
    gVector<T>         UpperBound()                       const;
    const T                  LowerBoundOfCoord(const int&)      const;
    const T                  UpperBoundOfCoord(const int&)      const;
    const T                  HeightInCoord(const int&)          const;
    const gInterval<T>       CartesianFactor(const int&)        const;
    const gRectangle<T>      SameCenterDoubleSideLengths()      const;
    const gRectangle<T>      CubeContainingCrcmscrbngSphere()   const;
    const gRectangle<T>      Orthant(const gArray<int>&)        const;
    const gVector<T>         SideLengths()                      const;
    const T                  MaximalSideLength()                const;
    bool                     Contains(const gVector<T> &)       const;
    bool                     Contains(const gRectangle<T> &)    const;
    const T                  Volume()                           const;
    const gVector<T>         Center()                           const;
    const gRectangle<T>      BoundingRectangle()                const;
    const gList<gVector<T> > VertexList()                       const;
    const int                NumberOfCellsInSubdivision()       const;
    const gRectangle<T>      SubdivisionCell(const int&)        const;
    const T                  DiameterSquared()                  const;

    // output
    void Output(gOutput &) const;
};

template <class T> gOutput &operator<<(gOutput &, const gRectangle<T> &);

  //-------------
  // Conversion:
  //-------------

template <class T> gRectangle<gDouble> TogDouble(const gRectangle<T>&);

#endif // RECTANGL_H