#pragma once

#include "TagEdit.h"

class TagInterface
{
	public: static TagEdit currentTag;
};

TagEdit TagInterface::currentTag = ("");
