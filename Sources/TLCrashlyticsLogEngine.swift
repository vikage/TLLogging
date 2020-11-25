//
//  TLCrashlyticsLogEngine.swift
//
//  Created by Thanh Vu on 25/11/2020.
//

import Foundation
import FirebaseCrashlytics
public class TLCrashlyticsLogEngine: TLLoggingEngine {
    public func log(_ format: String, _ args: CVarArg...) {
        Crashlytics.crashlytics().log(String.init(format: format, args))
    }
    
    public init() {
        
    }
}
