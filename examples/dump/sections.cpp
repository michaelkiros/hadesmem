// Copyright (C) 2010-2015 Joshua Boyce
// See the file COPYING for copying permission.

#include "sections.hpp"

#include <iostream>
#include <iterator>

#include <hadesmem/pelib/nt_headers.hpp>
#include <hadesmem/pelib/pe_file.hpp>
#include <hadesmem/pelib/section.hpp>
#include <hadesmem/pelib/section_list.hpp>
#include <hadesmem/process.hpp>

#include "main.hpp"
#include "print.hpp"
#include "warning.hpp"

void DumpSections(hadesmem::Process const& process,
                  hadesmem::PeFile const& pe_file)
{
  hadesmem::SectionList const sections(process, pe_file);

  std::wostream& out = GetOutputStreamW();

  if (std::begin(sections) != std::end(sections))
  {
    WriteNewline(out);
    WriteNormal(out, L"Sections:", 1);
  }
  else
  {
    // Other checks on number of sections are done as part of header handling.
    hadesmem::NtHeaders const nt_hdrs(process, pe_file);
    if (nt_hdrs.GetNumberOfSections())
    {
      WriteNewline(out);
      WriteNormal(out, L"WARNING! Section list is inavlid.", 1);
      WarnForCurrentFile(WarningType::kUnsupported);
    }
  }

  // TODO: Add entropy dumping here and elsewhere.
  for (auto const& s : sections)
  {
    WriteNewline(out);
    if (s.IsVirtual())
    {
      WriteNormal(out, L"WARNING! Section is virtual.", 2);
      WarnForCurrentFile(WarningType::kSuspicious);
    }
    HandleLongOrUnprintableString(
      L"Name", L"section name", 2, WarningType::kSuspicious, s.GetName());
    WriteNamedHex(out, L"VirtualAddress", s.GetVirtualAddress(), 2);
    WriteNamedHex(out, L"VirtualSize", s.GetVirtualSize(), 2);
    WriteNamedHex(out, L"PointerToRawData", s.GetPointerToRawData(), 2);
    WriteNamedHex(out, L"SizeOfRawData", s.GetSizeOfRawData(), 2);
    WriteNamedHex(out, L"PointerToRelocations", s.GetPointerToRelocations(), 2);
    WriteNamedHex(out, L"PointerToLinenumbers", s.GetPointerToLinenumbers(), 2);
    WriteNamedHex(out, L"NumberOfRelocations", s.GetNumberOfRelocations(), 2);
    WriteNamedHex(out, L"NumberOfLinenumbers", s.GetNumberOfLinenumbers(), 2);
    WriteNamedHex(out, L"Characteristics", s.GetCharacteristics(), 2);

    if (pe_file.GetType() == hadesmem::PeFileType::kData &&
        s.GetPointerToRawData() + s.GetSizeOfRawData() > pe_file.GetSize())
    {
      WriteNewline(out);
      WriteNormal(out, L"WARNING! Section size is invalid.", 1);
      WarnForCurrentFile(WarningType::kSuspicious);
    }
  }
}
