#pragma once

#include <map>
#include <string>

enum ParallelismType
{
	None,
	CoarseStatic,
	CoarseDynamic,
	FineStatic,
	FineDynamic
};

static std::map<enum ParallelismType, std::string> PARALLELISM_TYPE_MAP
{
	{ParallelismType::None, "None"},
	{ParallelismType::CoarseStatic, "CoarseStatic"},
	{ParallelismType::CoarseDynamic, "CoarseDynamic"},
	{ParallelismType::FineStatic, "FineStatic"},
	{ParallelismType::FineDynamic, "FineDynamic"},
};
