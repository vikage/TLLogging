# TLLogging

[![CocoaPods compatible](https://img.shields.io/badge/CocoaPods-compatible-green.svg?style=flat)](https://cocoapods.org)
TLLogging is logging framework for iOS.

# Installation
### From CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C and Swift, which automates and simplifies the process of using 3rd-party libraries like `TLLogging` in your projects. First, add the following line to your [Podfile](http://guides.cocoapods.org/using/using-cocoapods.html):

```ruby
pod 'TLLogging'
```

# Register log engine
Add these line to `didFinishLaunchingWithOptions` function in your AppDelegate to register log engine.
(see sample Xcode project)
```swift
TLLogging.addLogEngine(TLConsoleLogEngine())
TLLogging.addLogEngine(TLCrashlyticsLogEngine())
```
# Usage
```swift
TLLogging.log("Application start with options \(launchOptions ?? [:])")
```

# Debug check
Debug check is a useful function to trap your debugger when the variable value is unexpected
```swift
DCHECK(<#conditional#>)
```

# License
`TLLogging` is distributed under the terms and conditions of the [MIT license](https://github.com/SVProgressHUD/SVProgressHUD/blob/master/LICENSE).