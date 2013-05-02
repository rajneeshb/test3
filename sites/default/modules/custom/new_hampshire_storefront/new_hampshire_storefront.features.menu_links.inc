<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function new_hampshire_storefront_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-nav-1:http://www.avtranz.com/about.php
  $menu_links['menu-footer-nav-1:http://www.avtranz.com/about.php'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'link_path' => 'http://www.avtranz.com/about.php',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-footer-nav-1:http://www.avtranz.com/contact.php
  $menu_links['menu-footer-nav-1:http://www.avtranz.com/contact.php'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'link_path' => 'http://www.avtranz.com/contact.php',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-footer-nav-1:http://www.avtranz.com/privacy.php
  $menu_links['menu-footer-nav-1:http://www.avtranz.com/privacy.php'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'link_path' => 'http://www.avtranz.com/privacy.php',
    'router_path' => '',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-footer-nav-1:http://www.avtranz.com/terms.php
  $menu_links['menu-footer-nav-1:http://www.avtranz.com/terms.php'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'link_path' => 'http://www.avtranz.com/terms.php',
    'router_path' => '',
    'link_title' => 'Terms of Use',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-footer-nav-1:node/1725
  $menu_links['menu-footer-nav-1:node/1725'] = array(
    'menu_name' => 'menu-footer-nav-1',
    'link_path' => 'node/1725',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => 'Frequently Asked Questions',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-footer-nav-2:http://www.avtranz.com/about.php
  $menu_links['menu-footer-nav-2:http://www.avtranz.com/about.php'] = array(
    'menu_name' => 'menu-footer-nav-2',
    'link_path' => 'http://www.avtranz.com/about.php',
    'router_path' => '',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-footer-nav-2:http://www.avtranz.com/contact.php
  $menu_links['menu-footer-nav-2:http://www.avtranz.com/contact.php'] = array(
    'menu_name' => 'menu-footer-nav-2',
    'link_path' => 'http://www.avtranz.com/contact.php',
    'router_path' => '',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-home-nav:node/2
  $menu_links['menu-home-nav:node/2'] = array(
    'menu_name' => 'menu-home-nav',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'More Info',
    'options' => array(
      'attributes' => array(
        'class' => 'moreinfo',
        'title' => 'More info about how this works',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-home-nav:node/add/order
  $menu_links['menu-home-nav:node/add/order'] = array(
    'menu_name' => 'menu-home-nav',
    'link_path' => 'node/add/order',
    'router_path' => 'node/add/order',
    'link_title' => 'Request',
    'options' => array(
      'attributes' => array(
        'class' => 'request',
        'title' => 'Request a court transcript',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-home-nav:user/register
  $menu_links['menu-home-nav:user/register'] = array(
    'menu_name' => 'menu-home-nav',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create Account',
    'options' => array(
      'attributes' => array(
        'class' => 'create',
        'title' => 'Set up a user account',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-left-nav:checkstatus
  $menu_links['menu-left-nav:checkstatus'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'checkstatus',
    'router_path' => 'checkstatus',
    'link_title' => 'Check',
    'options' => array(
      'attributes' => array(
        'class' => 'check',
        'title' => 'Check the status of a transcript',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-47',
  );
  // Exported menu link: menu-left-nav:node
  $menu_links['menu-left-nav:node'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'node',
    'router_path' => 'node',
    'link_title' => 'Test sub item',
    'options' => array(
      'attributes' => array(
        'title' => 'Testing nested items',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'checkstatus',
  );
  // Exported menu link: menu-left-nav:node/2
  $menu_links['menu-left-nav:node/2'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'More Info',
    'options' => array(
      'attributes' => array(
        'name' => 'about how this works',
        'class' => 'moreinfo',
        'title' => 'More Information',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-left-nav:node/2424
  $menu_links['menu-left-nav:node/2424'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'node/2424',
    'router_path' => 'node/%',
    'link_title' => 'Admin',
    'options' => array(
      'attributes' => array(
        'class' => 'admin',
        'title' => 'Administration tasks',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-left-nav:node/add/order
  $menu_links['menu-left-nav:node/add/order'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'node/add/order',
    'router_path' => 'node/add/order',
    'link_title' => 'Request',
    'options' => array(
      'attributes' => array(
        'class' => 'request',
        'title' => 'Request a court transcript',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-left-nav:user/register
  $menu_links['menu-left-nav:user/register'] = array(
    'menu_name' => 'menu-left-nav',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create',
    'options' => array(
      'attributes' => array(
        'class' => 'create',
        'title' => 'set up a new account',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Admin');
  t('Check');
  t('Contact');
  t('Create');
  t('Create Account');
  t('FAQ');
  t('More Info');
  t('Privacy Policy');
  t('Request');
  t('Terms of Use');
  t('Test sub item');


  return $menu_links;
}
