#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#include "Entry.h"

class VolumeInfo
{
public:
	VolumeInfo();
	~VolumeInfo();

	bool isEmptyVolume() const;
	uint32_t getEntryTableOffset() const;

	void write(fstream& file) const;
	void read(fstream& file) const;
	bool checkSignature(fstream& file) const;
	
	void seekToHeadOfEntryTable_g(fstream& file) const;
	void seekToHeadOfEntryTable_p(fstream& file) const;
	
	bool isEndOfEntryTable_g(fstream& file) const;

	void updateAfterDel(Entry const* entry);
	void updateAfterSetPassword(size_t const& oldPasswordLen, size_t const& newPasswordLen);
	
	/*===== CALL IN PAIR =====*/
	void updateOffsetEntryTable(uint32_t const& newOffsetEntryTable);
	void updateSizeEntryTable(uint32_t const& newTailPosEntryTable);
	/*========================*/

private:
	/*==========*/
	uint32_t Signature;
	uint32_t SizeEntryTable;
	uint32_t OffsetEntryTable;
	/*==========*/
};
