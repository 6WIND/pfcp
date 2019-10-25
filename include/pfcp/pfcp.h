/* SPDX-License-Identifier: Apache-2.0
 * Copyright 2019 6WIND S.A.
 */

#ifndef _pfcp_h_
#define _pfcp_h_

/* 7.2.2.1-1 PFCP header */

struct pfcp_hdr {
	uint8_t version:3,   /* version 1 */
		spare:2,
		fo:1,        /* another PFCP follow */
		mp:1,        /* message priotiy present */
		s:1;         /* SEID present */
	uint8_t type;
	uint16_t len;
	union {
		struct {
			uint64_t seid;
			uint32_t seq:24,
				 priority:4;
				 spare:4;
		} s;
		struct {
			uint32_t seq:24,
				 spare:8;
		} no_s;
	} u;
} __attribute__ ((packed));

#define PFCP_UDP_PORT 8805

#define PFCP_MSG_NODE_RESERVED          0
#define PFCP_MSG_NODE_HB_REQ            1 /* PFCP Heartbeat Request */
#define PFCP_MSG_NODE_HB_RESP           2 /* PFCP Heartbeat Response */
#define PFCP_MSG_NODE_PFDM_REQ          3 /* PFCP PFD Management Request */
#define PFCP_MSG_NODE_PFDM_RESP         4 /* PFCP PFD Management Response */
#define PFCP_MSG_NODE_ASETUP_REQ        5 /* PFCP Association Setup Request */
#define PFCP_MSG_NODE_ASETUP_RESP       6 /* PFCP Association Setup Response */
#define PFCP_MSG_NODE_AUPDATE_REQ       7 /* PFCP Association Update Request */
#define PFCP_MSG_NODE_AUPDATE_RESP      8 /* PFCP Association Update Response */
#define PFCP_MSG_NODE_ARELEASE_REQ      9 /* PFCP Association Release Request */
#define PFCP_MSG_NODE_ARELEASE_RESP    10 /* PFCP Association Release Response */
#define PFCP_MSG_NODE_VERSION_NOTSUPP  11 /* PFCP Version Not Supported Response */
#define PFCP_MSG_NODE_REPORT_REQ       12 /* PFCP Node Report Request */
#define PFCP_MSG_NODE_REPORT_RESP      13 /* PFCP Node Report Response */
#define PFCP_MSG_NODE_SSET_DEL_REQ     14 /* PFCP Session Set Deletion Request */
#define PFCP_MSG_NODE_SSET_DEL_RESP    15 /* PFCP Session Set Deletion Response */

#define PFCP_MSG_SESS_EST_REQ          50 /* PFCP Session Establishment Request */
#define PFCP_MSG_SESS_EST_RESP         51 /* PFCP Session Establishment Response */
#define PFCP_MSG_SESS_MOD_REQ          52 /* PFCP Session Modification Request */
#define PFCP_MSG_SESS_MOD_RESP         53 /* PFCP Session Modification Response */
#define PFCP_MSG_SESS_DEL_REQ          54 /* PFCP Session Deletion Request */
#define PFCP_MSG_SESS_DEL_RESP         55 /* PFCP Session Deletion Response */
#define PFCP_MSG_SESS_REP_REQ          56 /* PFCP Session Report Request */
#define PFCP_MSG_SESS_REP_RESP         57 /* PFCP Session Report Response */

#endif
