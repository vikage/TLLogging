Pod::Spec.new do |spec|
  spec.name         = 'TLLogging'
  spec.version      = '1.0.3'
  spec.license      = { :type => 'MIT' }
  spec.homepage     = 'https://thanhvu.dev'
  spec.authors      = { 'Thanh Vu' => 'thanhg@luongthien.com' }
  spec.summary      = 'Logging base collections.'
  spec.source       = { :git => 'https://github.com/thanhdev2703/TLLogging.git', :tag => '1.0.3' }
  spec.source_files = 'Sources/*.swift', 'Sources/*.m', "Sources/*.h"
  spec.platform     = :ios, "11.0"
  spec.swift_versions = ['5.0']
end
