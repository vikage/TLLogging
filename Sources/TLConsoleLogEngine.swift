//
//  TLConsoleLogEngine.swift
//
//  Created by Thanh Vu on 25/11/2020.
//

import Foundation

public class TLConsoleLogEngine: TLLoggingEngine {
    public func log(_ content: String) {
        NSLog("%@", content)
    }
    
    public init() {
        
    }
}
