<?php

/**
 * @file
 * Entity property info file.
 */

/**
 * Implements hook_entity_property_info().
 */
function dir_topweb_entity_property_info() {
  $info = array();
  // Add 'rank' property to dir_link.
  $info['dir_link']['properties']['rank'] = array(
    'label' => t('Rank'),
    'descriptoin' => t('List of ranks of the link.'),
    'type' => 'list<dir_rank>',
    'computed' => TRUE,
    'getter callback' => 'dir_link_rank_entity_property_getter',
  );
  // Add 'ranks' property to dir_link.
  $info['dir_link']['properties']['ranks'] = array(
    'label' => t('Ranks'),
    'descriptoin' => t('List of ranks of the link by types.'),
    'type' => 'struct',
    'property info' => dir_link_ranks_entity_property_info(),
    'computed' => TRUE,
    'getter callback' => 'dir_link_ranks_entity_property_getter',
  );
  // Add 'ranking' property to dir_link.
  $info['dir_link']['properties']['ranking'] = array(
    'label' => t('Ranking'),
    'descriptoin' => t('Computed ranking score from all ranking sources of the link.'),
    'type' => 'decimal',
    'computed' => TRUE,
    'getter callback' => 'dir_link_ranking_entity_property_getter',
  );

  return $info;
}

/**
 * Helper function to generate the ranks property info for dir_link.
 */
function dir_link_ranks_entity_property_info() {
  $info = array();
  $entity_info = entity_get_info('dir_rank');
  foreach ($entity_info['bundles'] as $bundle => $bundle_info) {
    $info[$bundle] = array(
      'label' => $bundle_info['label'],
      'description' => t('@rank is a rank score of link.', array('@rank' => $bundle_info['label'])),
      'type' => 'dir_rank',
    );
  }

  return $info;
}
