//
//  TLLoggingUtil.swift
//  TrumpVoiceChange
//
//  Created by Thanh Vu on 18/11/2020.
//

import Foundation

public func DCHECK(_ value: Bool, file: String = #file, function: String = #function, line: Int = #line) {
    Objc_DCHECK(value, file, function, Int32(line))
}
