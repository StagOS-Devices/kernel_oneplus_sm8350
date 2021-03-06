/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 *
 */

#ifndef __DRIVERS_INTERCONNECT_QCOM_ICC_BCM_VOTER_H__
#define __DRIVERS_INTERCONNECT_QCOM_ICC_BCM_VOTER_H__

#include <soc/qcom/cmd-db.h>
#include <soc/qcom/rpmh.h>
#include <soc/qcom/tcs.h>

#include "icc-rpmh.h"

#define DEFINE_QBCM(_name, _bcmname, _keepalive, _voter_idx, _numnodes, ...)\
		static struct qcom_icc_bcm _name = {			\
		.name = _bcmname,					\
		.keepalive = _keepalive,				\
		.num_nodes = _numnodes,					\
		.voter_idx = _voter_idx,				\
		.nodes = { __VA_ARGS__ },				\
	}

struct bcm_voter *of_bcm_voter_get(struct device *dev, const char *name);
void qcom_icc_bcm_voter_add(struct bcm_voter *voter, struct qcom_icc_bcm *bcm);
int qcom_icc_bcm_voter_commit(struct bcm_voter *voter);
void qcom_icc_bcm_voter_clear_init(struct bcm_voter *voter);

#endif
