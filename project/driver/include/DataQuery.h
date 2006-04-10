/*
 * Copyright (C) 2005,2006 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */
#ifndef DATAQUERY_H
#define DATAQUERY_H

#include "librets.h"
#include "ezretsfwd.h"
#include "Query.h"
#include "librets/SearchRequest.h"

namespace odbcrets
{

class DataQuery : public Query
{
  public:
    DataQuery(RetsSTMT* stmt, bool useCompactFormat,
              librets::DmqlQueryPtr dmqlQuery);

    virtual SQLRETURN execute();

    virtual std::ostream & print(std::ostream & out) const;

  protected:
    virtual void prepareResultSet();
    virtual SQLRETURN doRetsQuery();

    librets::SearchRequest::FormatType mSearchFormat;
    librets::DmqlQueryPtr mDmqlQuery;
};

}

#endif /* DATAQUERY_H */

/* Local Variables: */
/* mode: c++ */
/* End: */