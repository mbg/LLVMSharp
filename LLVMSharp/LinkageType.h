#pragma once

namespace LLVM
{
	public enum class LinkageType
	{
		ExternalLinkage = 0,
		AvailableExternallyLinkage, 
		LinkOnceAnyLinkage, 
		LinkOnceODRLinkage, 
		WeakAnyLinkage,   
		WeakODRLinkage,   
		AppendingLinkage, 
		InternalLinkage,  
		PrivateLinkage,    
		LinkerPrivateLinkage, 
		LinkerPrivateWeakLinkage, 
		LinkerPrivateWeakDefAutoLinkage,
		DLLImportLinkage,   ///< Function to be imported from DLL
		DLLExportLinkage,   ///< Function to be accessible from DLL.
		ExternalWeakLinkage,///< ExternalWeak linkage description.
		CommonLinkage       ///< Tentative definitions.
	};
}