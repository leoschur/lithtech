// ----------------------------------------------------------------------- //
//
// MODULE  : ClientSaveLoadMgr.h
//
// PURPOSE : Manages the Saving and Loading of games for client.
//
// CREATED : 02/07/02
//
// (c) 2002 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef __CLIENTSAVELOADMGR_H__
#define __CLIENTSAVELOADMGR_H__

#include "SaveLoadMgr.h"

// 
// Globals...
//

class CClientSaveLoadMgr;
extern CClientSaveLoadMgr *g_pClientSaveLoadMgr;


class CClientSaveLoadMgr : public CSaveLoadMgr
{
	public : // Methods...

		CClientSaveLoadMgr( );
		virtual ~CClientSaveLoadMgr( );
		CClientSaveLoadMgr& operator=(const CClientSaveLoadMgr&)=delete;
		CClientSaveLoadMgr& operator=(CClientSaveLoadMgr&&)=delete;

		virtual bool	Init( char const* pszProfileName, bool bUseMultiplayerFolders );
		virtual void	Term( );

		bool	OnCommandOn( int nCommand );
		bool	CanSaveGame() const;
		bool	CanLoadGame() const;
		
		bool	QuickSave();
		bool	QuickLoad();

		bool	ReloadLevel();
		bool	ContinueGame();

		bool	SaveGameSlot( uint32 nSlot, char const* pszSaveName );
		bool	LoadGameSlot( uint32 nSlot );

		bool	OnMessage( uint8 messageID, ILTMessage_Read& msg );

	private : // Methods...

		bool	HandleSaveData( ILTMessage_Read& msg );
		bool	HandleSaveGameMsg( ILTMessage_Read& msg );


	private : // Members...
};

#endif // __CLIENTSAVELOADMGR_H__