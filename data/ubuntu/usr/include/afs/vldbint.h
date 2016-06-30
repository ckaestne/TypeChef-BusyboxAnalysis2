/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_VLDBINT_
#define	_RXGEN_VLDBINT_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
#include "rx/rx_globals.h"
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
#include "rx/rx_globals.h"
#else	/* KERNEL */
#include <afs/param.h>
#include <afs/stds.h>
#include <sys/types.h>
#include <rx/xdr.h>
#include <rx/rx.h>
#include <rx/rx_globals.h>
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

#define VL_STATINDEX 15
#include <afs/vl_opcodes.h> /* directly to other places */
#ifdef KERNEL
#define afs_xdr_array(a,b,c,d,e,f) afs_xdr_arrayN(a,b,c,d,e,f)
#endif
#define VldbVersion "4"
#define VLDBVERSION_4 4
#define VLDBVERSION 3
#define OVLDBVERSION 2
#define VL_MAXNAMELEN 65
#define OMAXNSERVERS 8
#define NMAXNSERVERS 13
#define MAXTYPES 3

struct VldbUpdateEntry {
	afs_uint32 Mask;
	char name[VL_MAXNAMELEN];
	afs_int32 spares3;
	afs_int32 flags;
	afs_uint32 ReadOnlyId;
	afs_uint32 BackupId;
	afs_uint32 cloneId;
	afs_int32 nModifiedRepsites;
	afs_uint32 RepsitesMask[OMAXNSERVERS];
	afs_int32 RepsitesTargetServer[OMAXNSERVERS];
	afs_int32 RepsitesTargetPart[OMAXNSERVERS];
	afs_int32 RepsitesNewServer[OMAXNSERVERS];
	afs_int32 RepsitesNewPart[OMAXNSERVERS];
	afs_int32 RepsitesNewFlags[OMAXNSERVERS];
};
typedef struct VldbUpdateEntry VldbUpdateEntry;
bool_t xdr_VldbUpdateEntry(XDR *xdrs, VldbUpdateEntry *objp);

#define VLUPDATE_VOLUMENAME 0x0001
#define VLUPDATE_FLAGS 0x0004
#define VLUPDATE_READONLYID 0x0008
#define VLUPDATE_BACKUPID 0x0010
#define VLUPDATE_REPSITES 0x0020
#define VLUPDATE_CLONEID 0x0080
#define VLUPDATE_VOLNAMEHASH 0x0100
#define VLUPDATE_RWID 0x0200
#define VLUPDATE_REPS_DELETE 0x0100
#define VLUPDATE_REPS_ADD 0x0200
#define VLUPDATE_REPS_MODSERV 0x0400
#define VLUPDATE_REPS_MODPART 0x0800
#define VLUPDATE_REPS_MODFLAG 0x1000
#define VLSERVER_FLAG_UUID 0x0010
#define DEFAULTBULK 10000

typedef struct bulk {
	u_int bulk_len;
	char *bulk_val;
} bulk;
bool_t xdr_bulk(XDR *xdrs, bulk *objp);


struct VldbListByAttributes {
	afs_uint32 Mask;
	afs_int32 server;
	afs_int32 partition;
	afs_int32 spares3;
	afs_uint32 volumeid;
	afs_int32 flag;
};
typedef struct VldbListByAttributes VldbListByAttributes;
bool_t xdr_VldbListByAttributes(XDR *xdrs, VldbListByAttributes *objp);

#define VLLIST_SERVER 0x1
#define VLLIST_PARTITION 0x2
#define VLLIST_VOLUMEID 0x8
#define VLLIST_FLAG 0x10

struct vldbentry {
	char name[VL_MAXNAMELEN];
	afs_int32 spares3;
	afs_int32 nServers;
	afs_int32 serverNumber[OMAXNSERVERS];
	afs_int32 serverPartition[OMAXNSERVERS];
	afs_int32 serverFlags[OMAXNSERVERS];
	afs_uint32 volumeId[MAXTYPES];
	afs_uint32 cloneId;
	afs_int32 flags;
};
typedef struct vldbentry vldbentry;
bool_t xdr_vldbentry(XDR *xdrs, vldbentry *objp);


struct nvldbentry {
	char name[VL_MAXNAMELEN];
	afs_int32 nServers;
	afs_int32 serverNumber[NMAXNSERVERS];
	afs_int32 serverPartition[NMAXNSERVERS];
	afs_int32 serverFlags[NMAXNSERVERS];
	afs_uint32 volumeId[MAXTYPES];
	afs_uint32 cloneId;
	afs_int32 flags;
	afs_int32 matchindex;
	afs_int32 spares2;
	afs_int32 spares3;
	afs_int32 spares4;
	afs_int32 spares5;
	afs_int32 spares6;
	afs_int32 spares7;
	afs_int32 spares8;
	afs_int32 spares9;
};
typedef struct nvldbentry nvldbentry;
bool_t xdr_nvldbentry(XDR *xdrs, nvldbentry *objp);


struct ListAddrByAttributes {
	afs_int32 Mask;
	afs_uint32 ipaddr;
	afs_int32 index;
	afs_int32 spare1;
	afsUUID uuid;
};
typedef struct ListAddrByAttributes ListAddrByAttributes;
bool_t xdr_ListAddrByAttributes(XDR *xdrs, ListAddrByAttributes *objp);

#define VLADDR_IPADDR 0x1
#define VLADDR_INDEX 0x2
#define VLADDR_UUID 0x4

struct uvldbentry {
	char name[VL_MAXNAMELEN];
	afs_int32 nServers;
	afsUUID serverNumber[NMAXNSERVERS];
	afs_int32 serverUnique[NMAXNSERVERS];
	afs_int32 serverPartition[NMAXNSERVERS];
	afs_int32 serverFlags[NMAXNSERVERS];
	afs_uint32 volumeId[MAXTYPES];
	afs_uint32 cloneId;
	afs_int32 flags;
	afs_int32 matchindex;
	afs_int32 spares2;
	afs_int32 spares3;
	afs_int32 spares4;
	afs_int32 spares5;
	afs_int32 spares6;
	afs_int32 spares7;
	afs_int32 spares8;
	afs_int32 spares9;
};
typedef struct uvldbentry uvldbentry;
bool_t xdr_uvldbentry(XDR *xdrs, uvldbentry *objp);


struct vital_vlheader {
	afs_int32 vldbversion;
	afs_int32 headersize;
	afs_int32 freePtr;
	afs_int32 eofPtr;
	afs_int32 allocs;
	afs_int32 frees;
	afs_uint32 MaxVolumeId;
	afs_int32 totalEntries[MAXTYPES];
};
typedef struct vital_vlheader vital_vlheader;
bool_t xdr_vital_vlheader(XDR *xdrs, vital_vlheader *objp);

#define MAX_NUMBER_OPCODES 50

struct vldstats {
	afs_uint32 start_time;
	afs_int32 requests[MAX_NUMBER_OPCODES];
	afs_int32 aborts[MAX_NUMBER_OPCODES];
	afs_int32 reserved[5];
};
typedef struct vldstats vldstats;
bool_t xdr_vldstats(XDR *xdrs, vldstats *objp);

#define VLOP_MOVE 0x10
#define VLOP_RELEASE 0x20
#define VLOP_BACKUP 0x40
#define VLOP_DELETE 0x80
#define VLOP_DUMP 0x100
#define VLOP_ALLOPERS ( VLOP_MOVE | VLOP_RELEASE | VLOP_BACKUP | VLOP_DELETE | VLOP_DUMP)
#define VLF_RWEXISTS 0x1000 /* flags for whole vldb entry */
#define VLF_ROEXISTS 0x2000
#define VLF_BACKEXISTS 0x4000
#define VLF_DFSFILESET 0x8000 /* Volume is really DFS fileset */
#define VLSF_NEWREPSITE 0x01 /* flags for indiv. server entry */
#define VLSF_ROVOL 0x02
#define VLSF_RWVOL 0x04
#define VLSF_BACKVOL 0x08
#define VLSF_DONTUSE 0x20 /* no conflict with VLSERVER_FLAG_UUID */

typedef struct bulkentries {
	u_int bulkentries_len;
	vldbentry *bulkentries_val;
} bulkentries;
bool_t xdr_bulkentries(XDR *xdrs, bulkentries *objp);


typedef struct nbulkentries {
	u_int nbulkentries_len;
	nvldbentry *nbulkentries_val;
} nbulkentries;
bool_t xdr_nbulkentries(XDR *xdrs, nbulkentries *objp);


typedef struct ubulkentries {
	u_int ubulkentries_len;
	uvldbentry *ubulkentries_val;
} ubulkentries;
bool_t xdr_ubulkentries(XDR *xdrs, ubulkentries *objp);


typedef struct bulkaddrs {
	u_int bulkaddrs_len;
	afs_uint32 *bulkaddrs_val;
} bulkaddrs;
bool_t xdr_bulkaddrs(XDR *xdrs, bulkaddrs *objp);


struct VLCallBack {
	afs_uint32 CallBackVersion;
	afs_uint32 ExpirationTime;
	afs_uint32 CallBackType;
	afs_uint32 Handle;
};
typedef struct VLCallBack VLCallBack;
bool_t xdr_VLCallBack(XDR *xdrs, VLCallBack *objp);


#include <rx/rx_multi.h>
#define multi_VL_ProbeServer() \
	multi_Body(StartVL_ProbeServer(multi_call), EndVL_ProbeServer(multi_call))


extern int StartVL_ProbeServer(
	/*IN */ struct rx_call *z_call);

extern int EndVL_ProbeServer(
	/*IN */ struct rx_call *z_call);

extern int VL_ProbeServer(
	/*IN */ struct rx_connection *z_conn);

extern int ubik_VL_ProbeServer(
	struct ubik_client *aclient, afs_int32 aflags);

extern afs_int32 SVL_ProbeServer(
	/*IN */ struct rx_call *z_call);

extern int VL_GetEntryByNameO(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * volumename,
	/*OUT*/ vldbentry * entry);

extern int ubik_VL_GetEntryByNameO(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * volumename,
	/*OUT*/ vldbentry * entry);

extern afs_int32 SVL_GetEntryByNameO(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * volumename,
	/*OUT*/ vldbentry * entry);

extern int VL_GetEntryByNameN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * volumename,
	/*OUT*/ nvldbentry * entry);

extern int ubik_VL_GetEntryByNameN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * volumename,
	/*OUT*/ nvldbentry * entry);

extern afs_int32 SVL_GetEntryByNameN(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * volumename,
	/*OUT*/ nvldbentry * entry);

extern int VL_GetEntryByNameU(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * volumename,
	/*OUT*/ uvldbentry * entry);

extern int ubik_VL_GetEntryByNameU(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * volumename,
	/*OUT*/ uvldbentry * entry);

extern afs_int32 SVL_GetEntryByNameU(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * volumename,
	/*OUT*/ uvldbentry * entry);

extern int VL_GetAddrsU(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ ListAddrByAttributes * inaddr,
	/*OUT*/ afsUUID * uuidp1,
	/*OUT*/ afs_int32 * uniquifier,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);

extern int ubik_VL_GetAddrsU(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ ListAddrByAttributes * inaddr,
	/*OUT*/ afsUUID * uuidp1,
	/*OUT*/ afs_int32 * uniquifier,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);

extern afs_int32 SVL_GetAddrsU(
	/*IN */ struct rx_call *z_call,
	/*IN */ ListAddrByAttributes * inaddr,
	/*OUT*/ afsUUID * uuidp1,
	/*OUT*/ afs_int32 * uniquifier,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);
#if !defined(KERNEL)

typedef struct single_vldbentry *vldblist;
bool_t xdr_vldblist(XDR *xdrs, vldblist *objp);


struct single_vldbentry {
	vldbentry VldbEntry;
	vldblist next_vldb;
};
typedef struct single_vldbentry single_vldbentry;
bool_t xdr_single_vldbentry(XDR *xdrs, single_vldbentry *objp);


struct vldb_list {
	vldblist node;
};
typedef struct vldb_list vldb_list;
bool_t xdr_vldb_list(XDR *xdrs, vldb_list *objp);


typedef struct single_nvldbentry *nvldblist;
bool_t xdr_nvldblist(XDR *xdrs, nvldblist *objp);


struct single_nvldbentry {
	nvldbentry VldbEntry;
	nvldblist next_vldb;
};
typedef struct single_nvldbentry single_nvldbentry;
bool_t xdr_single_nvldbentry(XDR *xdrs, single_nvldbentry *objp);


struct nvldb_list {
	nvldblist node;
};
typedef struct nvldb_list nvldb_list;
bool_t xdr_nvldb_list(XDR *xdrs, nvldb_list *objp);


extern int VL_CreateEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ vldbentry * newentry);

extern int ubik_VL_CreateEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ vldbentry * newentry);

extern afs_int32 SVL_CreateEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ vldbentry * newentry);

extern int VL_DeleteEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype);

extern int ubik_VL_DeleteEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype);

extern afs_int32 SVL_DeleteEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype);

extern int VL_GetEntryByID(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ vldbentry * entry);

extern int ubik_VL_GetEntryByID(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ vldbentry * entry);

extern afs_int32 SVL_GetEntryByID(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ vldbentry * entry);

extern int VL_GetNewVolumeId(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 bumpcount,
	/*OUT*/ afs_uint32 * newvolumid);

extern int ubik_VL_GetNewVolumeId(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 bumpcount,
	/*OUT*/ afs_uint32 * newvolumid);

extern afs_int32 SVL_GetNewVolumeId(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 bumpcount,
	/*OUT*/ afs_uint32 * newvolumid);

extern int VL_ReplaceEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ vldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern int ubik_VL_ReplaceEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ vldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern afs_int32 SVL_ReplaceEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ vldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern int VL_UpdateEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern int ubik_VL_UpdateEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern afs_int32 SVL_UpdateEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern int VL_SetLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 voloper);

extern int ubik_VL_SetLock(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 voloper);

extern afs_int32 SVL_SetLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 voloper);

extern int VL_ReleaseLock(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 ReleaseType);

extern int ubik_VL_ReleaseLock(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 ReleaseType);

extern afs_int32 SVL_ReleaseLock(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ afs_int32 ReleaseType);

extern int VL_ListEntry(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ vldbentry * entry);

extern int ubik_VL_ListEntry(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ vldbentry * entry);

extern afs_int32 SVL_ListEntry(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ vldbentry * entry);

extern int VL_ListAttributes(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkentries * blkentries);

extern int ubik_VL_ListAttributes(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkentries * blkentries);

extern afs_int32 SVL_ListAttributes(
	/*IN */ struct rx_call *z_call,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkentries * blkentries);

extern int VL_LinkedList(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ vldb_list * linkedentries);

extern int ubik_VL_LinkedList(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ vldb_list * linkedentries);

extern afs_int32 SVL_LinkedList(
	/*IN */ struct rx_call *z_call,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ vldb_list * linkedentries);

extern int VL_GetStats(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ vldstats * stats,
	/*OUT*/ vital_vlheader * vital_header);

extern int ubik_VL_GetStats(
	struct ubik_client *aclient, afs_int32 aflags,
	/*OUT*/ vldstats * stats,
	/*OUT*/ vital_vlheader * vital_header);

extern afs_int32 SVL_GetStats(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ vldstats * stats,
	/*OUT*/ vital_vlheader * vital_header);

extern int VL_GetAddrs(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 Handle,
	/*IN */ afs_int32 spare2,
	/*OUT*/ VLCallBack * spare3,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);

extern int ubik_VL_GetAddrs(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 Handle,
	/*IN */ afs_int32 spare2,
	/*OUT*/ VLCallBack * spare3,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);

extern afs_int32 SVL_GetAddrs(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 Handle,
	/*IN */ afs_int32 spare2,
	/*OUT*/ VLCallBack * spare3,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ bulkaddrs * blkaddrs);

extern int VL_ChangeAddr(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 ip1,
	/*IN */ afs_uint32 ip2);

extern int ubik_VL_ChangeAddr(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 ip1,
	/*IN */ afs_uint32 ip2);

extern afs_int32 SVL_ChangeAddr(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 ip1,
	/*IN */ afs_uint32 ip2);

extern int VL_CreateEntryN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ nvldbentry * newentry);

extern int ubik_VL_CreateEntryN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ nvldbentry * newentry);

extern afs_int32 SVL_CreateEntryN(
	/*IN */ struct rx_call *z_call,
	/*IN */ nvldbentry * newentry);

extern int VL_GetEntryByIDN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ nvldbentry * entry);

extern int ubik_VL_GetEntryByIDN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ nvldbentry * entry);

extern afs_int32 SVL_GetEntryByIDN(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*OUT*/ nvldbentry * entry);

extern int VL_ReplaceEntryN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ nvldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern int ubik_VL_ReplaceEntryN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ nvldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern afs_int32 SVL_ReplaceEntryN(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 Volid,
	/*IN */ afs_int32 voltype,
	/*IN */ nvldbentry * newentry,
	/*IN */ afs_int32 ReleaseType);

extern int VL_ListEntryN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ nvldbentry * entry);

extern int ubik_VL_ListEntryN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ nvldbentry * entry);

extern afs_int32 SVL_ListEntryN(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 previous_index,
	/*OUT*/ afs_int32 * count,
	/*OUT*/ afs_int32 * next_index,
	/*OUT*/ nvldbentry * entry);

extern int VL_ListAttributesN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries);

extern int ubik_VL_ListAttributesN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries);

extern afs_int32 SVL_ListAttributesN(
	/*IN */ struct rx_call *z_call,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries);

extern int VL_LinkedListN(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nvldb_list * linkedentries);

extern int ubik_VL_LinkedListN(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nvldb_list * linkedentries);

extern afs_int32 SVL_LinkedListN(
	/*IN */ struct rx_call *z_call,
	/*IN */ VldbListByAttributes * attributes,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nvldb_list * linkedentries);

extern int VL_UpdateEntryByName(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * volumename,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern int ubik_VL_UpdateEntryByName(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ char * volumename,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern afs_int32 SVL_UpdateEntryByName(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * volumename,
	/*IN */ VldbUpdateEntry * UpdateEntry,
	/*IN */ afs_int32 ReleaseType);

extern int VL_RegisterAddrs(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afsUUID * uuidp,
	/*IN */ afs_int32 spare1,
	/*IN */ bulkaddrs * ipaddr);

extern int ubik_VL_RegisterAddrs(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ afsUUID * uuidp,
	/*IN */ afs_int32 spare1,
	/*IN */ bulkaddrs * ipaddr);

extern afs_int32 SVL_RegisterAddrs(
	/*IN */ struct rx_call *z_call,
	/*IN */ afsUUID * uuidp,
	/*IN */ afs_int32 spare1,
	/*IN */ bulkaddrs * ipaddr);

extern int VL_ListAttributesN2(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ VldbListByAttributes * attributes,
	/*IN */ char * volumename,
	/*IN */ afs_int32 startindex,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries,
	/*OUT*/ afs_int32 * nextstartindex);

extern int ubik_VL_ListAttributesN2(
	struct ubik_client *aclient, afs_int32 aflags,
	/*IN */ VldbListByAttributes * attributes,
	/*IN */ char * volumename,
	/*IN */ afs_int32 startindex,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries,
	/*OUT*/ afs_int32 * nextstartindex);

extern afs_int32 SVL_ListAttributesN2(
	/*IN */ struct rx_call *z_call,
	/*IN */ VldbListByAttributes * attributes,
	/*IN */ char * volumename,
	/*IN */ afs_int32 startindex,
	/*OUT*/ afs_int32 * nentries,
	/*OUT*/ nbulkentries * blkentries,
	/*OUT*/ afs_int32 * nextstartindex);
#endif /* !defined(KERNEL) */

extern int VL_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: VL_ */
#define VL_LOWEST_OPCODE   501
#define VL_HIGHEST_OPCODE	534
#define VL_NUMBER_OPCODES	28

#define VL_NO_OF_STAT_FUNCS	28

AFS_RXGEN_EXPORT
extern const char *VL_function_names[];

#endif	/* _RXGEN_VLDBINT_ */
