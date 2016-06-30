/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_BUDB_
#define	_RXGEN_BUDB_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
#include <ubik.h>
#else	/* UKERNEL */
#include "h/types.h"
#ifndef	SOCK_DGRAM  /* XXXXX */
#include "h/socket.h"
#endif
struct ubik_client;
#ifndef	DTYPE_SOCKET  /* XXXXX */
#ifndef AFS_LINUX22_ENV
#include "h/file.h"
#endif
#endif
#ifndef	S_IFMT  /* XXXXX */
#include "h/stat.h"
#endif
#if defined (AFS_OBSD_ENV) && !defined (MLEN)
#include "sys/mbuf.h"
#endif
#ifndef	IPPROTO_UDP /* XXXXX */
#include "netinet/in.h"
#endif
#ifndef	DST_USA  /* XXXXX */
#include "h/time.h"
#endif
#ifndef AFS_LINUX22_ENV
#include "rpc/types.h"
#endif /* AFS_LINUX22_ENV */
#ifndef	XDR_GETLONG /* XXXXX */
#ifdef AFS_LINUX22_ENV
#ifndef quad_t
#define quad_t __quad_t
#define u_quad_t __u_quad_t
#endif
#endif
#include "rx/xdr.h"
#endif /* XDR_GETLONG */
#endif   /* UKERNEL */
#include "afs/rxgen_consts.h"
#include "afs_osi.h"
#include "rx/rx.h"
#else	/* KERNEL */
#include <afs/param.h>
#include <afs/stds.h>
#include <sys/types.h>
#include <rx/xdr.h>
#include <rx/rx.h>
#include <afs/rxgen_consts.h>
#include <ubik.h>
#endif	/* KERNEL */

#ifdef AFS_NT40_ENV
#ifndef AFS_RXGEN_EXPORT
#define AFS_RXGEN_EXPORT __declspec(dllimport)
#endif /* AFS_RXGEN_EXPORT */
#else /* AFS_NT40_ENV */
#define AFS_RXGEN_EXPORT
#endif /* AFS_NT40_ENV */

#ifndef NEVERDATE
#define NEVERDATE 037777777777 /* a date that will never come */
#endif
#ifndef Date
#define Date afs_uint32
#endif
#define BUDB_MAJORVERSION 2
#ifndef dumpId
#define dumpId afs_uint32
#endif
#define TB_DUMPSCHEDULE 0
#define TB_VOLUMESET 1
#define TB_TAPEHOSTS 2
#define TB_NUM 3 /* no. of block types */
#define TB_MAX 6 /* unused items are spares */

struct budb_principal {
	char name[256];
	char instance[128];
	char cell[256];
};
typedef struct budb_principal budb_principal;
bool_t xdr_budb_principal(XDR *xdrs, budb_principal *objp);


struct budb_tapeSet {
	afs_int32 id;
	char tapeServer[32];
	char format[32];
	afs_int32 maxTapes;
	afs_int32 a;
	afs_int32 b;
};
typedef struct budb_tapeSet budb_tapeSet;
bool_t xdr_budb_tapeSet(XDR *xdrs, budb_tapeSet *objp);

#define budb_MakeTapeName(name,set,seq) sprintf (name, (set)->format, (set)->a*(seq) + (set)->b)

struct budb_dumpEntry {
	afs_uint32 id;
	afs_uint32 parent;
	afs_int32 level;
	afs_int32 flags;
	char volumeSetName[32];
	char dumpPath[256];
	char name[32];
	afs_uint32 created;
	afs_uint32 incTime;
	afs_int32 nVolumes;
	struct budb_tapeSet tapes;
	struct budb_principal dumper;
	afs_uint32 initialDumpID;
	afs_uint32 appendedDumpID;
};
typedef struct budb_dumpEntry budb_dumpEntry;
bool_t xdr_budb_dumpEntry(XDR *xdrs, budb_dumpEntry *objp);

#define BUDB_DUMP_INCOMPLETE (1<<0) /* some vols omitted due to errors */
#define BUDB_DUMP_TAPEERROR (1<<1) /* tape error during dump */
#define BUDB_DUMP_INPROGRESS (1<<2)
#define BUDB_DUMP_ABORTED (1<<3) /* aborted: prob. dump unavailable */
#define BUDB_DUMP_XBSA_NSS (1<<8) /* dump was done with a client    */
#define BUDB_DUMP_BUTA (1<<11) /* (used by ADSM buta) == 0x800 */
#define BUDB_DUMP_ADSM (1<<12) /* (used by XBSA/ADSM buta) == 0x1000 */

struct budb_tapeEntry {
	char name[32];
	afs_int32 flags;
	afs_uint32 written;
	afs_uint32 expires;
	afs_uint32 nMBytes;
	afs_uint32 nBytes;
	afs_int32 nFiles;
	afs_int32 nVolumes;
	afs_int32 seq;
	afs_int32 labelpos;
	afs_int32 useCount;
	afs_int32 useKBytes;
	afs_uint32 dump;
};
typedef struct budb_tapeEntry budb_tapeEntry;
bool_t xdr_budb_tapeEntry(XDR *xdrs, budb_tapeEntry *objp);

#define BUDB_TAPE_TAPEERROR (1<<0)
#define BUDB_TAPE_DELETED (1<<1)
#define BUDB_TAPE_BEINGWRITTEN (1<<2) /* writing in progress */
#define BUDB_TAPE_ABORTED (1<<3) /* aborted: tape probably garbaged */
#define BUDB_TAPE_STAGED (1<<4) /* not yet on permanent media */
#define BUDB_TAPE_WRITTEN (1<<5) /* tape writing finished: all OK */

struct budb_volumeEntry {
	char name[32];
	afs_int32 flags;
	afs_int32 id;
	char server[32];
	afs_int32 partition;
	afs_int32 tapeSeq;
	afs_int32 position;
	afs_uint32 clone;
	afs_uint32 incTime;
	afs_int32 startByte;
	afs_uint32 nBytes;
	afs_int32 seq;
	afs_uint32 dump;
	char tape[32];
};
typedef struct budb_volumeEntry budb_volumeEntry;
bool_t xdr_budb_volumeEntry(XDR *xdrs, budb_volumeEntry *objp);

#define BUDB_VOL_TAPEERROR (1<<0) /* tape problem during dump */
#define BUDB_VOL_FILEERROR (1<<1) /* voldump aborted during dump */
#define BUDB_VOL_BEINGWRITTEN (1<<2)
#define BUDB_VOL_FIRSTFRAG (1<<3) /* same as low bits of tape position */
#define BUDB_VOL_LASTFRAG (1<<4)
#define BUDB_VOL_ABORTED (1<<5) /* aborted: vol probably undumped */
#define BUDB_STATINDEX 17
#define BUDB_OP_NAMES (0x7)
#define BUDB_OP_STARTS (0x7<<3)
#define BUDB_OP_ENDS (0x7<<6)
#define BUDB_OP_TIMES (0x3<<9)
#define BUDB_OP_MISC (0xff<<16)
#define BUDB_OP_DUMPNAME (1<<0)
#define BUDB_OP_VOLUMENAME (2<<0)
#define BUDB_OP_TAPENAME (3<<0)
#define BUDB_OP_TAPESEQ (4<<0)
#define BUDB_OP_STARTTIME (1<<3)
#define BUDB_OP_RANGE (1<<6)
#define BUDB_OP_NPREVIOUS (2<<6)
#define BUDB_OP_NFOLLOWING (3<<6)
#define BUDB_OP_DUMPID (2<<3)
#define BUDB_OP_CLONETIME (1<<9) /* use clone time */
#define BUDB_OP_DUMPTIME (2<<9) /* use dump time (create?) */
#define BUDB_OP_INCTIME (3<<9) /* use inc time */
#define BUDB_OP_FIRSTFRAG (1<<16)
#define BUDB_MAX_RETURN_LIST 1000

typedef struct budb_volumeList {
	u_int budb_volumeList_len;
	budb_volumeEntry *budb_volumeList_val;
} budb_volumeList;
bool_t xdr_budb_volumeList(XDR *xdrs, budb_volumeList *objp);


typedef struct budb_dumpList {
	u_int budb_dumpList_len;
	budb_dumpEntry *budb_dumpList_val;
} budb_dumpList;
bool_t xdr_budb_dumpList(XDR *xdrs, budb_dumpList *objp);


typedef struct budb_tapeList {
	u_int budb_tapeList_len;
	budb_tapeEntry *budb_tapeList_val;
} budb_tapeList;
bool_t xdr_budb_tapeList(XDR *xdrs, budb_tapeList *objp);


typedef struct budb_dumpsList {
	u_int budb_dumpsList_len;
	afs_int32 *budb_dumpsList_val;
} budb_dumpsList;
bool_t xdr_budb_dumpsList(XDR *xdrs, budb_dumpsList *objp);


typedef struct charListT {
	u_int charListT_len;
	char *charListT_val;
} charListT;
bool_t xdr_charListT(XDR *xdrs, charListT *objp);

#define BUDB_TEXT_COMPLETE 1
#define SD_DBHEADER 1
#define SD_DUMP 2
#define SD_TAPE 3
#define SD_VOLUME 4
#define SD_TEXT_DUMPSCHEDULE 5
#define SD_TEXT_VOLUMESET 6
#define SD_TEXT_TAPEHOSTS 7
#define SD_END 8
#define BUDB_OP_DATES (0x01)
#define BUDB_OP_GROUPID (0x02)
#define BUDB_OP_APPDUMP (0x01)
#define BUDB_OP_DBDUMP (0x02)

struct DbHeader {
	afs_int32 dbversion;
	afs_int32 created;
	char cell[256];
	afs_uint32 lastDumpId;
	afs_uint32 lastInstanceId;
	afs_uint32 lastTapeId;
};
typedef struct DbHeader DbHeader;
bool_t xdr_DbHeader(XDR *xdrs, DbHeader *objp);


struct structDumpHeader {
	afs_int32 type;
	afs_int32 structversion;
	afs_int32 size;
};
typedef struct structDumpHeader structDumpHeader;
bool_t xdr_structDumpHeader(XDR *xdrs, structDumpHeader *objp);


extern int BUDB_AddVolume(
	/*IN */ struct rx_connection *z_conn,
	/*I/O*/ struct budb_volumeEntry * vol);

extern int ubik_BUDB_AddVolume(
	struct ubik_client *aclient, afs_int32 aflags,
	/*I/O*/ struct budb_volumeEntry * vol);

extern afs_int32 SBUDB_AddVolume(
	/*IN */ struct rx_call *z_call,
	/*I/O*/ struct budb_volumeEntry * vol);

extern int BUDB_CreateDump(
	/*IN */ struct rx_connection *z_conn,
	/*I/O*/ struct budb_dumpEntry * dump);

extern int ubik_BUDB_CreateDump(
	struct ubik_client *aclient, afs_int32 aflags,
	/*I/O*/ struct budb_dumpEntry * dump);

extern afs_int32 SBUDB_CreateDump(
	/*IN */ struct rx_call *z_call,
	/*I/O*/ struct budb_dumpEntry * dump);

extern int BUDB_DeleteDump(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 id,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps);

extern int ubik_BUDB_DeleteDump(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 id,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps);

extern afs_int32 SBUDB_DeleteDump(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 id,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps);

extern int BUDB_DeleteTape(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ struct budb_tapeEntry * tape);

extern int ubik_BUDB_DeleteTape(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ struct budb_tapeEntry * tape);

extern afs_int32 SBUDB_DeleteTape(
	/*IN */ struct rx_call *z_call,
	/*IN */ struct budb_tapeEntry * tape);

extern int BUDB_DeleteVDP(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * dsname,
	/*IN */ char * dumpPath,
	/*IN */ afs_int32 curDumpId);

extern int ubik_BUDB_DeleteVDP(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * dsname,
	/*IN */ char * dumpPath,
	/*IN */ afs_int32 curDumpId);

extern afs_int32 SBUDB_DeleteVDP(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * dsname,
	/*IN */ char * dumpPath,
	/*IN */ afs_int32 curDumpId);

extern int BUDB_FindClone(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 dumpID,
	/*IN */ char * volName,
	/*I/O*/ afs_int32 * clonetime);

extern int ubik_BUDB_FindClone(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 dumpID,
	/*IN */ char * volName,
	/*I/O*/ afs_int32 * clonetime);

extern afs_int32 SBUDB_FindClone(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 dumpID,
	/*IN */ char * volName,
	/*I/O*/ afs_int32 * clonetime);

extern int BUDB_FindDump(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * volumeName,
	/*IN */ afs_int32 beforeDate,
	/*I/O*/ struct budb_dumpEntry * deptr);

extern int ubik_BUDB_FindDump(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * volumeName,
	/*IN */ afs_int32 beforeDate,
	/*I/O*/ struct budb_dumpEntry * deptr);

extern afs_int32 SBUDB_FindDump(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * volumeName,
	/*IN */ afs_int32 beforeDate,
	/*I/O*/ struct budb_dumpEntry * deptr);

extern int BUDB_FindLatestDump(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * vsname,
	/*IN */ char * dname,
	/*OUT*/ budb_dumpEntry * dumpentry);

extern int ubik_BUDB_FindLatestDump(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * vsname,
	/*IN */ char * dname,
	/*OUT*/ budb_dumpEntry * dumpentry);

extern afs_int32 SBUDB_FindLatestDump(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * vsname,
	/*IN */ char * dname,
	/*OUT*/ budb_dumpEntry * dumpentry);

extern int BUDB_MakeDumpAppended(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 appendedDumpID,
	/*IN */ afs_int32 intialDumpID,
	/*IN */ afs_int32 startTapeSeq);

extern int ubik_BUDB_MakeDumpAppended(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 appendedDumpID,
	/*IN */ afs_int32 intialDumpID,
	/*IN */ afs_int32 startTapeSeq);

extern afs_int32 SBUDB_MakeDumpAppended(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 appendedDumpID,
	/*IN */ afs_int32 intialDumpID,
	/*IN */ afs_int32 startTapeSeq);

extern int BUDB_FindLastTape(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 dumpID,
	/*OUT*/ struct budb_dumpEntry * dumpEntry,
	/*OUT*/ struct budb_tapeEntry * tapeEntry,
	/*OUT*/ struct budb_volumeEntry * volEntry);

extern int ubik_BUDB_FindLastTape(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 dumpID,
	/*OUT*/ struct budb_dumpEntry * dumpEntry,
	/*OUT*/ struct budb_tapeEntry * tapeEntry,
	/*OUT*/ struct budb_volumeEntry * volEntry);

extern afs_int32 SBUDB_FindLastTape(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 dumpID,
	/*OUT*/ struct budb_dumpEntry * dumpEntry,
	/*OUT*/ struct budb_tapeEntry * tapeEntry,
	/*OUT*/ struct budb_volumeEntry * volEntry);

extern int BUDB_FinishDump(
	/*IN */ struct rx_connection *z_conn,
	/*I/O*/ struct budb_dumpEntry * dump);

extern int ubik_BUDB_FinishDump(
	struct ubik_client *aclient, afs_int32 aflags,
	/*I/O*/ struct budb_dumpEntry * dump);

extern afs_int32 SBUDB_FinishDump(
	/*IN */ struct rx_call *z_call,
	/*I/O*/ struct budb_dumpEntry * dump);

extern int BUDB_FinishTape(
	/*IN */ struct rx_connection *z_conn,
	/*I/O*/ struct budb_tapeEntry * tape);

extern int ubik_BUDB_FinishTape(
	struct ubik_client *aclient, afs_int32 aflags,
	/*I/O*/ struct budb_tapeEntry * tape);

extern afs_int32 SBUDB_FinishTape(
	/*IN */ struct rx_call *z_call,
	/*I/O*/ struct budb_tapeEntry * tape);

extern int BUDB_GetDumps(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_dumpList * dumps);

extern int ubik_BUDB_GetDumps(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_dumpList * dumps);

extern afs_int32 SBUDB_GetDumps(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_dumpList * dumps);

extern int BUDB_GetTapes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ struct budb_tapeList * tapes);

extern int ubik_BUDB_GetTapes(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ struct budb_tapeList * tapes);

extern afs_int32 SBUDB_GetTapes(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ struct budb_tapeList * tapes);

extern int BUDB_GetVolumes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_volumeList * volumes);

extern int ubik_BUDB_GetVolumes(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_volumeList * volumes);

extern afs_int32 SBUDB_GetVolumes(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 majorVersion,
	/*IN */ afs_int32 flags,
	/*IN */ char * name,
	/*IN */ afs_int32 start,
	/*IN */ afs_int32 end,
	/*IN */ afs_int32 index,
	/*OUT*/ afs_int32 * nextIndex,
	/*OUT*/ afs_int32 * dbUpdate,
	/*I/O*/ budb_volumeList * volumes);

extern int BUDB_UseTape(
	/*IN */ struct rx_connection *z_conn,
	/*I/O*/ struct budb_tapeEntry * tape,
	/*OUT*/ afs_int32 * new);

extern int ubik_BUDB_UseTape(
	struct ubik_client *aclient, afs_int32 aflags,
	/*I/O*/ struct budb_tapeEntry * tape,
	/*OUT*/ afs_int32 * new);

extern afs_int32 SBUDB_UseTape(
	/*IN */ struct rx_call *z_call,
	/*I/O*/ struct budb_tapeEntry * tape,
	/*OUT*/ afs_int32 * new);

extern int BUDB_GetText(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 maxLength,
	/*IN */ afs_int32 offset,
	/*OUT*/ afs_int32 * nextOffset,
	/*OUT*/ charListT * charListPtr);

extern int ubik_BUDB_GetText(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 maxLength,
	/*IN */ afs_int32 offset,
	/*OUT*/ afs_int32 * nextOffset,
	/*OUT*/ charListT * charListPtr);

extern afs_int32 SBUDB_GetText(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 maxLength,
	/*IN */ afs_int32 offset,
	/*OUT*/ afs_int32 * nextOffset,
	/*OUT*/ charListT * charListPtr);

extern int BUDB_GetTextVersion(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 textType,
	/*OUT*/ afs_uint32 * tversion);

extern int ubik_BUDB_GetTextVersion(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 textType,
	/*OUT*/ afs_uint32 * tversion);

extern afs_int32 SBUDB_GetTextVersion(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 textType,
	/*OUT*/ afs_uint32 * tversion);

extern int BUDB_SaveText(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 offset,
	/*IN */ afs_int32 flags,
	/*IN */ charListT * charListPtr);

extern int ubik_BUDB_SaveText(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 offset,
	/*IN */ afs_int32 flags,
	/*IN */ charListT * charListPtr);

extern afs_int32 SBUDB_SaveText(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 lockHandle,
	/*IN */ afs_int32 textType,
	/*IN */ afs_int32 offset,
	/*IN */ afs_int32 flags,
	/*IN */ charListT * charListPtr);

extern int BUDB_FreeAllLocks(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 instanceId);

extern int ubik_BUDB_FreeAllLocks(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 instanceId);

extern afs_int32 SBUDB_FreeAllLocks(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 instanceId);

extern int BUDB_FreeLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 lockHandle);

extern int ubik_BUDB_FreeLock(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 lockHandle);

extern afs_int32 SBUDB_FreeLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 lockHandle);

extern int BUDB_GetInstanceId(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_uint32 * instanceId);

extern int ubik_BUDB_GetInstanceId(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ afs_uint32 * instanceId);

extern afs_int32 SBUDB_GetInstanceId(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_uint32 * instanceId);

extern int BUDB_GetLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 instanceId,
	/*IN */ afs_int32 lockName,
	/*IN */ afs_int32 expiration,
	/*OUT*/ afs_uint32 * lockHandle);

extern int ubik_BUDB_GetLock(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 instanceId,
	/*IN */ afs_int32 lockName,
	/*IN */ afs_int32 expiration,
	/*OUT*/ afs_uint32 * lockHandle);

extern afs_int32 SBUDB_GetLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 instanceId,
	/*IN */ afs_int32 lockName,
	/*IN */ afs_int32 expiration,
	/*OUT*/ afs_uint32 * lockHandle);

extern int BUDB_DbVerify(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * status,
	/*OUT*/ afs_int32 * orphans,
	/*OUT*/ afs_int32 * host);

extern int ubik_BUDB_DbVerify(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ afs_int32 * status,
	/*OUT*/ afs_int32 * orphans,
	/*OUT*/ afs_int32 * host);

extern afs_int32 SBUDB_DbVerify(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * status,
	/*OUT*/ afs_int32 * orphans,
	/*OUT*/ afs_int32 * host);

extern int BUDB_DumpDB(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ int firstcall,
	/*IN */ afs_int32 maxLength,
	/*OUT*/ charListT * charListPtr,
	/*OUT*/ afs_int32 * flags);

extern int ubik_BUDB_DumpDB(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ int firstcall,
	/*IN */ afs_int32 maxLength,
	/*OUT*/ charListT * charListPtr,
	/*OUT*/ afs_int32 * flags);

extern afs_int32 SBUDB_DumpDB(
	/*IN */ struct rx_call *z_call,
	/*IN */ int firstcall,
	/*IN */ afs_int32 maxLength,
	/*OUT*/ charListT * charListPtr,
	/*OUT*/ afs_int32 * flags);

extern int BUDB_RestoreDbHeader(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ struct DbHeader * header);

extern int ubik_BUDB_RestoreDbHeader(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ struct DbHeader * header);

extern afs_int32 SBUDB_RestoreDbHeader(
	/*IN */ struct rx_call *z_call,
	/*IN */ struct DbHeader * header);

extern int BUDB_T_GetVersion(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * majorVersion);

extern int ubik_BUDB_T_GetVersion(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ afs_int32 * majorVersion);

extern afs_int32 SBUDB_T_GetVersion(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * majorVersion);

extern int BUDB_T_DumpHashTable(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 type,
	/*IN */ char * filename);

extern int ubik_BUDB_T_DumpHashTable(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 type,
	/*IN */ char * filename);

extern afs_int32 SBUDB_T_DumpHashTable(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 type,
	/*IN */ char * filename);

extern int BUDB_T_DumpDatabase(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * filename);

extern int ubik_BUDB_T_DumpDatabase(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * filename);

extern afs_int32 SBUDB_T_DumpDatabase(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * filename);

extern int BUDB_AddVolumes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ struct budb_volumeList * vols);

extern int ubik_BUDB_AddVolumes(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ struct budb_volumeList * vols);

extern afs_int32 SBUDB_AddVolumes(
	/*IN */ struct rx_call *z_call,
	/*IN */ struct budb_volumeList * vols);

extern int BUDB_ListDumps(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 sflags,
	/*IN */ char * name,
	/*IN */ afs_int32 group,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps,
	/*I/O*/ budb_dumpsList * flags);

extern int ubik_BUDB_ListDumps(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 sflags,
	/*IN */ char * name,
	/*IN */ afs_int32 group,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps,
	/*I/O*/ budb_dumpsList * flags);

extern afs_int32 SBUDB_ListDumps(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 sflags,
	/*IN */ char * name,
	/*IN */ afs_int32 group,
	/*IN */ afs_uint32 fromTime,
	/*IN */ afs_uint32 toTime,
	/*I/O*/ budb_dumpsList * dumps,
	/*I/O*/ budb_dumpsList * flags);

extern int BUDB_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: BUDB_ */
#define BUDB_LOWEST_OPCODE   0
#define BUDB_HIGHEST_OPCODE	30
#define BUDB_NUMBER_OPCODES	31

#endif	/* _RXGEN_BUDB_ */
