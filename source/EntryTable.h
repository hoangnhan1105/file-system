#pragma once
#include "VolumeInfo.h"
#include "Entry.h"
#include "Folder.h"
#include "GUI.h"

class EntryTable
{
	friend class Volume;

public:
	EntryTable();
	~EntryTable();
  
	void read(fstream& file, VolumeInfo const& volumeInfo);
	void write(fstream& file) const;

	void add(Entry const& entry);
	
	void updateAfterDel(Entry const* entry);

private:
	// The root folder of the volume.
	Entry* Root;
	// The list of files and folders in the whole volume (including subfiles).
	//
	// Each element in the list is a generic pointer of type `Entry*`
	// which points to either a File or Folder object (OOP feature).
	vector<Entry*> EntryList;
};

