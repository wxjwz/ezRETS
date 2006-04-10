/*
 * Copyright (C) 2005 National Association of REALTORS(R)
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
#ifndef METADATAVIEW_H
#define METADATAVIEW_H

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include "librets.h"

namespace odbcrets
{
typedef std::pair<librets::MetadataResource*,
                  librets::MetadataClass*> ResourceClassPair;
typedef boost::shared_ptr<ResourceClassPair> ResourceClassPairPtr;
typedef std::vector<ResourceClassPairPtr> ResourceClassPairVector;
typedef boost::shared_ptr<ResourceClassPairVector> ResourceClassPairVectorPtr;

typedef std::pair<std::string, std::string> TableMetadataPair;
typedef std::vector<TableMetadataPair> TableMetadataVector;
typedef boost::shared_ptr<TableMetadataVector> TableMetadataVectorPtr;

class MetadataView : public librets::SqlMetadata
{
  public:
    MetadataView(bool standardNames, librets::RetsMetadata* metadata);

    ResourceClassPairVectorPtr getResourceClassPairs();
    ResourceClassPairPtr getResourceClassPairBySQLTable(std::string tableName);

    librets::MetadataClass* getClass(
        std::string resName, std::string className);

    librets::MetadataTable* getTable(
        std::string resName, std::string className, std::string tableName);
    librets::MetadataTable* getTable(
        librets::MetadataClass* clazz, std::string tableName);

    librets::MetadataTable* getKeyFieldTable(
        librets::MetadataClass* clazz, std::string keyField);

    librets::MetadataTableList getTablesForClass(
        librets::MetadataClass* clazz);

    librets::MetadataResource* getResource(std::string resName);
    librets::MetadataResourceList getResources();

    bool IsLookupColumn(librets::MetadataTable* table);
    virtual bool IsLookupColumn(std::string tableName, std::string columnName);

    /**
     * Searches the metadata and takes Resource:Class combinations and
     * turns them into table names of the form "data:Resource:Class".
     * This function can (and will) throw exceptions.
     */
    TableMetadataVectorPtr getSQLTableMetadata();
    TableMetadataVectorPtr getSQLTableMetadata(std::string name);

    /**
     * Makes a table name based on the Resource and Class passed in.
     * If we're in StandardName mode, and one of the value doesn't
     * have a standardname, we return an empty string.
     */
    std::string makeSQLTableName(librets::MetadataResource* resource,
                                 librets::MetadataClass* clazz);

  private:
    librets::MetadataTable* getTable(
        librets::MetadataClass* clazz, std::string tableName, bool stdNames);
    
    typedef std::map<std::string, librets::MetadataResource*> ResourceMap;
    typedef boost::shared_ptr<ResourceMap> ResourceMapPtr;

    typedef std::pair<librets::MetadataResource*, std::string> ClassMapKey;
    typedef std::map<ClassMapKey, librets::MetadataClass*> ClassMap;
    typedef boost::shared_ptr<ClassMap> ClassMapPtr;

    typedef std::pair<librets::MetadataClass*, std::string> TableMapKey;
    typedef std::map<TableMapKey, librets::MetadataTable*> TableMap;
    typedef boost::shared_ptr<TableMap> TableMapPtr;
    typedef std::map<librets::MetadataClass*, bool> TablesInitMap;
    typedef boost::shared_ptr<TablesInitMap> TablesInitMapPtr;
    
    void initResources();
    void initClasses();
    bool areTablesForClassInited(librets::MetadataClass* clazz);
    void initTablesForClass(librets::MetadataClass* clazz);

    bool mStandardNames;
    librets::RetsMetadata* mMetadataPtr;

    ResourceMapPtr mResourceBySysNamePtr;
    ResourceMapPtr mResourceByStdNamePtr;
    ClassMapPtr mClassSysMapPtr;
    ClassMapPtr mClassStdMapPtr;
    TableMapPtr mTableSysMapPtr;
    TableMapPtr mTableStdMapPtr;
    TablesInitMapPtr mTablesInitMapPtr;
};

}

#endif /* METADATAVIEW_H */

/* Local Variables: */
/* mode: c++ */
/* End: */
