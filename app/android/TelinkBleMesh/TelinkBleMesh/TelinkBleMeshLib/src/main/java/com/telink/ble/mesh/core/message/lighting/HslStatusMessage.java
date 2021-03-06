/********************************************************************************************************
 * @file     HslStatusMessage.java 
 *
 * @brief    for TLSR chips
 *
 * @author	 telink
 * @date     Sep. 30, 2010
 *
 * @par      Copyright (c) 2010, Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *           
 *			 The information contained herein is confidential and proprietary property of Telink 
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms 
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai) 
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in. 
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this 
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided. 
 *           
 *******************************************************************************************************/
package com.telink.ble.mesh.core.message.lighting;

import android.os.Parcel;
import android.os.Parcelable;

import com.telink.ble.mesh.core.MeshUtils;
import com.telink.ble.mesh.core.message.StatusMessage;

import java.nio.ByteOrder;

/**
 * There is no target info in status message
 *
 * @see HslTargetStatusMessage
 * Created by kee on 2019/8/20.
 */
public class HslStatusMessage extends StatusMessage implements Parcelable {

    private static final int DATA_LEN_COMPLETE = 7;

    private int lightness;

    private int hue;

    private int saturation;

    private byte remainingTime;

    /**
     * tag of is complete message
     */
    private boolean isComplete = false;

    public HslStatusMessage() {
    }

    protected HslStatusMessage(Parcel in) {
        lightness = in.readInt();
        hue = in.readInt();
        saturation = in.readInt();
        remainingTime = in.readByte();
        isComplete = in.readByte() != 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(lightness);
        dest.writeInt(hue);
        dest.writeInt(saturation);
        dest.writeByte(remainingTime);
        dest.writeByte((byte) (isComplete ? 1 : 0));
    }

    @Override
    public int describeContents() {
        return 0;
    }

    public static final Creator<HslStatusMessage> CREATOR = new Creator<HslStatusMessage>() {
        @Override
        public HslStatusMessage createFromParcel(Parcel in) {
            return new HslStatusMessage(in);
        }

        @Override
        public HslStatusMessage[] newArray(int size) {
            return new HslStatusMessage[size];
        }
    };

    @Override
    public void parse(byte[] params) {
        int index = 0;
        this.lightness = MeshUtils.bytes2Integer(params, index, 2, ByteOrder.LITTLE_ENDIAN);
        index += 2;
        this.hue = MeshUtils.bytes2Integer(params, index, 2, ByteOrder.LITTLE_ENDIAN);
        index += 2;
        this.saturation = MeshUtils.bytes2Integer(params, index, 2, ByteOrder.LITTLE_ENDIAN);
        index += 2;
        if (params.length == DATA_LEN_COMPLETE) {
            this.isComplete = true;
            this.remainingTime = params[index];
        }
    }

    public int getLightness() {
        return lightness;
    }

    public int getHue() {
        return hue;
    }

    public int getSaturation() {
        return saturation;
    }

    public byte getRemainingTime() {
        return remainingTime;
    }

    public boolean isComplete() {
        return isComplete;
    }
}
