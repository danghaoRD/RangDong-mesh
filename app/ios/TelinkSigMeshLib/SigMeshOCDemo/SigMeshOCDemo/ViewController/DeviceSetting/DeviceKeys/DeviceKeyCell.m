/********************************************************************************************************
* @file     DeviceKeyCell.m
*
* @brief    The cell of AppKey of NetKey.
*
* @author       Telink, 梁家誌
* @date         2020
*
* @par      Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd.
*           All rights reserved.
*
*           The information contained herein is confidential property of Telink
*           Semiconductor (Shanghai) Co., Ltd. and is available under the terms
*           of Commercial License Agreement between Telink Semiconductor (Shanghai)
*           Co., Ltd. and the licensee or the terms described here-in. This heading
*           MUST NOT be removed from this file.
*
*           Licensee shall not delete, modify or alter (or permit any third party to delete, modify, or
*           alter) any information contained herein in whole or in part except as expressly authorized
*           by Telink semiconductor (shanghai) Co., Ltd. Otherwise, licensee shall be solely responsible
*           for any claim to the extent arising out of or relating to such deletion(s), modification(s)
*           or alteration(s).
*
*           Licensees are granted free, non-transferable use of the information in this
*           file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided.
*
*******************************************************************************************************/
//
//  DeviceKeyCell.m
//  SigMeshOCDemo
//
//  Created by 梁家誌 on 2020/9/17.
//  Copyright © 2020 Telink. All rights reserved.
//

#import "DeviceKeyCell.h"

@implementation DeviceKeyCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setAppKeyModel:(SigAppkeyModel *)appKeyModel {
    _appKeyModel = appKeyModel;
    _detailLabel.text = [NSString stringWithFormat:@"%@%@",_appKeyModel == SigDataSource.share.curAppkeyModel ? @"[Current] " : @"",_appKeyModel.getAppKeyDetailString];
}

- (void)setNetKeyModel:(SigNetkeyModel *)netKeyModel {
    _netKeyModel = netKeyModel;
    _detailLabel.text = [NSString stringWithFormat:@"%@%@",_netKeyModel == SigDataSource.share.curNetkeyModel ? @"[Current] " : @"",_netKeyModel.getNetKeyDetailString];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
