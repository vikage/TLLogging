//
//  TLLogging.swift
//
//  Created by Thanh Vu on 25/11/2020.
//

import Foundation

public protocol TLLoggingEngine {
    func log(_ content: String)
}

final public class TLLogging {
    private static let shared = TLLogging()
    private var engines: [TLLoggingEngine] = []
    
    public static func addLogEngine(_ engine: TLLoggingEngine) {
        self.shared.engines.append(engine)
    }
}

public extension TLLogging {
    static func log(_ content: String) {
        self.shared.engines.forEach { (engine) in
            engine.log(content)
        }
    }
}
