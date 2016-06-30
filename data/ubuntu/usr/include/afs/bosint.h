/* Machine generated file -- Do NOT edit */

#ifndef	_RXGEN_BOSINT_
#define	_RXGEN_BOSINT_

#ifdef	KERNEL
/* The following 'ifndefs' are not a good solution to the vendor's omission of surrounding all system includes with 'ifndef's since it requires that this file is included after the system includes...*/
#include <afsconfig.h>
#include "afs/param.h"
#ifdef	UKERNEL
#include "afs/sysincludes.h"
#include "rx/xdr.h"
#include "rx/rx.h"
#include "rx/rx_globals.h"
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
#endif	/* KERNEL */

#ifdef AFS_NT40_ENV
#ifndef AFS_RXGEN_EXPORT
#define AFS_RXGEN_EXPORT __declspec(dllimport)
#endif /* AFS_RXGEN_EXPORT */
#else /* AFS_NT40_ENV */
#define AFS_RXGEN_EXPORT
#endif /* AFS_NT40_ENV */


typedef int bstring;
bool_t xdr_bstring(XDR *xdrs, bstring *objp);

#define BOZO_BSSIZE 256
#undef min

struct bozo_netKTime {
	int mask;
	short hour;
	short min;
	short sec;
	short day;
};
typedef struct bozo_netKTime bozo_netKTime;
bool_t xdr_bozo_netKTime(XDR *xdrs, bozo_netKTime *objp);


struct bozo_key {
	char data[8];
};
typedef struct bozo_key bozo_key;
bool_t xdr_bozo_key(XDR *xdrs, bozo_key *objp);


struct bozo_keyInfo {
	afs_int32 mod_sec;
	afs_int32 mod_usec;
	afs_uint32 keyCheckSum;
	afs_int32 spare2;
};
typedef struct bozo_keyInfo bozo_keyInfo;
bool_t xdr_bozo_keyInfo(XDR *xdrs, bozo_keyInfo *objp);


struct bozo_status {
	afs_int32 goal;
	afs_int32 fileGoal;
	afs_int32 procStartTime;
	afs_int32 procStarts;
	afs_int32 lastAnyExit;
	afs_int32 lastErrorExit;
	afs_int32 errorCode;
	afs_int32 errorSignal;
	afs_int32 flags;
	afs_int32 spare[8];
};
typedef struct bozo_status bozo_status;
bool_t xdr_bozo_status(XDR *xdrs, bozo_status *objp);

#define BOZO_HASCORE 1 /* core file exists */
#define BOZO_ERRORSTOP 2 /* stopped due to too many errors */
#define BOZO_BADDIRACCESS 4 /* bad mode bits on /usr/afs dirs */
#define BOZO_PRUNEOLD 1 /* prune .OLD files */
#define BOZO_PRUNEBAK 2 /* prune .BAK files */
#define BOZO_PRUNECORE 4 /* prune core files */
#define BOZO_STATINDEX 1

extern int BOZO_CreateBnode(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * type,
	/*IN */ char * instance,
	/*IN */ char * p1,
	/*IN */ char * p2,
	/*IN */ char * p3,
	/*IN */ char * p4,
	/*IN */ char * p5,
	/*IN */ char * p6);

extern afs_int32 SBOZO_CreateBnode(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * type,
	/*IN */ char * instance,
	/*IN */ char * p1,
	/*IN */ char * p2,
	/*IN */ char * p3,
	/*IN */ char * p4,
	/*IN */ char * p5,
	/*IN */ char * p6);

extern int BOZO_DeleteBnode(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance);

extern afs_int32 SBOZO_DeleteBnode(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance);

extern int BOZO_SetStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*IN */ afs_int32 status);

extern afs_int32 SBOZO_SetStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*IN */ afs_int32 status);

extern int BOZO_GetStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*OUT*/ afs_int32 * intStat,
	/*OUT*/ char * *statdescr);

extern afs_int32 SBOZO_GetStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*OUT*/ afs_int32 * intStat,
	/*OUT*/ char * *statdescr);

extern int BOZO_EnumerateInstance(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 instance,
	/*OUT*/ char * *iname);

extern afs_int32 SBOZO_EnumerateInstance(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 instance,
	/*OUT*/ char * *iname);

extern int BOZO_GetInstanceInfo(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*OUT*/ char * *type,
	/*OUT*/ struct bozo_status * status);

extern afs_int32 SBOZO_GetInstanceInfo(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*OUT*/ char * *type,
	/*OUT*/ struct bozo_status * status);

extern int BOZO_GetInstanceParm(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*IN */ afs_int32 num,
	/*OUT*/ char * *parm);

extern afs_int32 SBOZO_GetInstanceParm(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*IN */ afs_int32 num,
	/*OUT*/ char * *parm);

extern int BOZO_AddSUser(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name);

extern afs_int32 SBOZO_AddSUser(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_DeleteSUser(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name);

extern afs_int32 SBOZO_DeleteSUser(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_ListSUsers(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 an,
	/*OUT*/ char * *name);

extern afs_int32 SBOZO_ListSUsers(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 an,
	/*OUT*/ char * *name);

extern int BOZO_ListKeys(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 an,
	/*OUT*/ afs_int32 * kvno,
	/*OUT*/ struct bozo_key * key,
	/*OUT*/ struct bozo_keyInfo * keyinfo);

extern afs_int32 SBOZO_ListKeys(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 an,
	/*OUT*/ afs_int32 * kvno,
	/*OUT*/ struct bozo_key * key,
	/*OUT*/ struct bozo_keyInfo * keyinfo);

extern int BOZO_AddKey(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 an,
	/*IN */ struct bozo_key * key);

extern afs_int32 SBOZO_AddKey(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 an,
	/*IN */ struct bozo_key * key);

extern int BOZO_DeleteKey(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 an);

extern afs_int32 SBOZO_DeleteKey(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 an);

extern int BOZO_SetCellName(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name);

extern afs_int32 SBOZO_SetCellName(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_GetCellName(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ char * *name);

extern afs_int32 SBOZO_GetCellName(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ char * *name);

extern int BOZO_GetCellHost(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_uint32 awhich,
	/*OUT*/ char * *name);

extern afs_int32 SBOZO_GetCellHost(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_uint32 awhich,
	/*OUT*/ char * *name);

extern int BOZO_AddCellHost(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name);

extern afs_int32 SBOZO_AddCellHost(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_DeleteCellHost(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * name);

extern afs_int32 SBOZO_DeleteCellHost(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_SetTStatus(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*IN */ afs_int32 status);

extern afs_int32 SBOZO_SetTStatus(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*IN */ afs_int32 status);

extern int BOZO_ShutdownAll(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SBOZO_ShutdownAll(
	/*IN */ struct rx_call *z_call);

extern int BOZO_RestartAll(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SBOZO_RestartAll(
	/*IN */ struct rx_call *z_call);

extern int BOZO_StartupAll(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SBOZO_StartupAll(
	/*IN */ struct rx_call *z_call);

extern int BOZO_SetNoAuthFlag(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 flag);

extern afs_int32 SBOZO_SetNoAuthFlag(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 flag);

extern int BOZO_ReBozo(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SBOZO_ReBozo(
	/*IN */ struct rx_call *z_call);

extern int BOZO_Restart(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance);

extern afs_int32 SBOZO_Restart(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance);

extern int StartBOZO_Install(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * path,
	/*IN */ afs_int32 size,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 date);

extern int EndBOZO_Install(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SBOZO_Install(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * path,
	/*IN */ afs_int32 size,
	/*IN */ afs_int32 flags,
	/*IN */ afs_int32 date);

extern int BOZO_UnInstall(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * path);

extern afs_int32 SBOZO_UnInstall(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * path);

extern int BOZO_GetDates(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * path,
	/*OUT*/ afs_int32 * newtime,
	/*OUT*/ afs_int32 * baktime,
	/*OUT*/ afs_int32 * oldtime);

extern afs_int32 SBOZO_GetDates(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * path,
	/*OUT*/ afs_int32 * newtime,
	/*OUT*/ afs_int32 * baktime,
	/*OUT*/ afs_int32 * oldtime);

extern int BOZO_Exec(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * cmd);

extern afs_int32 SBOZO_Exec(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * cmd);

extern int BOZO_Prune(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 flags);

extern afs_int32 SBOZO_Prune(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 flags);

extern int BOZO_SetRestartTime(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 type,
	/*IN */ struct bozo_netKTime * restartTime);

extern afs_int32 SBOZO_SetRestartTime(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 type,
	/*IN */ struct bozo_netKTime * restartTime);

extern int BOZO_GetRestartTime(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 type,
	/*OUT*/ struct bozo_netKTime * restartTime);

extern afs_int32 SBOZO_GetRestartTime(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 type,
	/*OUT*/ struct bozo_netKTime * restartTime);

extern int StartBOZO_GetLog(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int EndBOZO_GetLog(
	/*IN */ struct rx_call *z_call);

extern afs_int32 SBOZO_GetLog(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * name);

extern int BOZO_WaitAll(
	/*IN */ struct rx_connection *z_conn);

extern afs_int32 SBOZO_WaitAll(
	/*IN */ struct rx_call *z_call);

extern int BOZO_GetInstanceStrings(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ char * instance,
	/*OUT*/ char * *errorName,
	/*OUT*/ char * *spare1,
	/*OUT*/ char * *spare2,
	/*OUT*/ char * *spare3);

extern afs_int32 SBOZO_GetInstanceStrings(
	/*IN */ struct rx_call *z_call,
	/*IN */ char * instance,
	/*OUT*/ char * *errorName,
	/*OUT*/ char * *spare1,
	/*OUT*/ char * *spare2,
	/*OUT*/ char * *spare3);

extern int BOZO_GetRestrictedMode(
	/*IN */ struct rx_connection *z_conn,
	/*OUT*/ afs_int32 * restmode);

extern afs_int32 SBOZO_GetRestrictedMode(
	/*IN */ struct rx_call *z_call,
	/*OUT*/ afs_int32 * restmode);

extern int BOZO_SetRestrictedMode(
	/*IN */ struct rx_connection *z_conn,
	/*IN */ afs_int32 restmode);

extern afs_int32 SBOZO_SetRestrictedMode(
	/*IN */ struct rx_call *z_call,
	/*IN */ afs_int32 restmode);

extern int BOZO_ExecuteRequest(struct rx_call *);

/* Opcode-related useful stats for package: BOZO_ */
#define BOZO_LOWEST_OPCODE   80
#define BOZO_HIGHEST_OPCODE	116
#define BOZO_NUMBER_OPCODES	37

#define BOZO_NO_OF_STAT_FUNCS	37

AFS_RXGEN_EXPORT
extern const char *BOZO_function_names[];

#endif	/* _RXGEN_BOSINT_ */
