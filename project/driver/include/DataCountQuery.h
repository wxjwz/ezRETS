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
#ifndef DATACOUNTQUERY_H
#define DATACOUNTQUERY_H

#include "librets.h"
#include "ezretsfwd.h"
#include "DataQuery.h"

namespace odbcrets
{

class DataCountQuery : public DataQuery
{
  public:
    DataCountQuery(RetsSTMT* stmt, bool useCompactFormat,
                   librets::DmqlQueryPtr dmqlQuery);

    virtual void prepareResultSet();

  protected:
    virtual SQLRETURN doRetsQuery();
};

}

#endif /* DATACOUNTQUERY_H */

/* Local Variables: */
/* mode: c++ */
/* End: */
